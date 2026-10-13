"""Receptor HTTP educativo de LAN; solo biblioteca estándar Python 3.10+."""
import argparse,json,sqlite3,math
from http.server import BaseHTTPRequestHandler,ThreadingHTTPServer
from pathlib import Path

def almacenar(db,key,dato):
    if not isinstance(dato,dict) or not {'nodo','id'}<=set(dato) or not set(dato)<={'nodo','id','valor'} or dato['nodo']!='nodo01' or type(dato['id']) is not int or not 0<dato['id']<=4294967295:
        return 400,{'error':'contrato: nodo01 e id entero positivo de 32 bits'}
    if 'valor' in dato and (type(dato['valor']) not in (int,float) or not math.isfinite(dato['valor'])):return 400,{'error':'valor numerico finito'}
    if key!=f"nodo01-{dato['id']}":return 400,{'error':'key no corresponde al registro'}
    cuerpo=json.dumps(dato,sort_keys=True,separators=(',',':'))
    with sqlite3.connect(db,timeout=5) as con:
        con.execute('CREATE TABLE IF NOT EXISTS eventos (clave TEXT PRIMARY KEY,cuerpo TEXT NOT NULL)')
        # Serializa la comprobación y escritura para solicitudes concurrentes.
        con.execute('BEGIN IMMEDIATE')
        previo=con.execute('SELECT cuerpo FROM eventos WHERE clave=?',(key,)).fetchone()
        if previo:
            if previo[0]!=cuerpo:return 409,{'error':'misma identidad, contenido distinto'}
            return 200,{'ack':key,'duplicado':True}
        con.execute('INSERT INTO eventos VALUES (?,?)',(key,cuerpo))
    return 201,{'ack':key,'duplicado':False}

class Handler(BaseHTTPRequestHandler):
    def enviar(self,code,obj):
        data=json.dumps(obj).encode();self.send_response(code)
        self.send_header('Content-Type','application/json');self.send_header('Content-Length',str(len(data)));self.end_headers();self.wfile.write(data)
    def do_GET(self):
        if self.path=='/medicion':self.enviar(200,{'nodo':'nodo01','temperatura_c':24.5,'source':'simulated'})
        elif self.path=='/salud':self.enviar(200,{'estado':'ok'})
        else:self.enviar(404,{'error':'ruta'})
    def do_POST(self):
        if self.path!='/eventos':self.enviar(404,{'error':'ruta'});return
        try:n=int(self.headers.get('Content-Length','0'))
        except ValueError:self.enviar(400,{'error':'longitud'});return
        if not 0<n<=1024:self.enviar(413,{'error':'tamano'});return
        if self.headers.get_content_type()!='application/json':self.enviar(415,{'error':'content-type'});return
        try:dato=json.loads(self.rfile.read(n))
        except (ValueError,UnicodeError):self.enviar(400,{'error':'JSON'});return
        try:code,obj=almacenar(self.server.db,self.headers.get('Idempotency-Key',''),dato)
        except sqlite3.Error:self.enviar(503,{'error':'almacenamiento no confirmado'});return
        self.enviar(code,obj)

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--host',default='127.0.0.1');p.add_argument('--port',type=int,default=8000);p.add_argument('--db',default='eventos.db');a=p.parse_args()
    servidor=ThreadingHTTPServer((a.host,a.port),Handler);servidor.db=Path(a.db)
    print(f'HTTP local {a.host}:{a.port}; SQLite {a.db}; sin TLS/autenticacion')
    try:servidor.serve_forever()
    except KeyboardInterrupt:pass
    finally:servidor.server_close()
