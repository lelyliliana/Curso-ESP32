import importlib.util,json,sqlite3,tempfile,threading,unittest,urllib.request,urllib.error
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('servicio',ROOT/'laboratorios/servicios/servidor.py')
s=importlib.util.module_from_spec(spec);spec.loader.exec_module(s)

class Receptor(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.db=Path(self.tmp.name)/'eventos.db'
    def tearDown(self):self.tmp.cleanup()
    def test_confirmacion_durable(self):
        status,body=s.almacenar(self.db,'nodo01-1',{'nodo':'nodo01','id':1})
        self.assertEqual((status,body['ack']),(201,'nodo01-1'))
        with sqlite3.connect(self.db) as c:self.assertEqual(c.execute('SELECT count(*) FROM eventos').fetchone()[0],1)
    def test_ack_perdido_y_reenvio(self):
        evento={'nodo':'nodo01','id':2};s.almacenar(self.db,'nodo01-2',evento)
        status,body=s.almacenar(self.db,'nodo01-2',evento)
        self.assertEqual(status,200);self.assertTrue(body['duplicado'])
        with sqlite3.connect(self.db) as c:self.assertEqual(c.execute('SELECT count(*) FROM eventos').fetchone()[0],1)
    def test_conflicto_no_sobrescribe(self):
        s.almacenar(self.db,'nodo01-3',{'nodo':'nodo01','id':3,'valor':24})
        self.assertEqual(s.almacenar(self.db,'nodo01-3',{'nodo':'nodo01','id':3,'valor':25})[0],409)
        with sqlite3.connect(self.db) as c:self.assertEqual(json.loads(c.execute('SELECT cuerpo FROM eventos').fetchone()[0])['valor'],24)
    def test_contrato_invalido(self):
        for dato in [{},[],{'nodo':'nodo01','id':True},{'nodo':'nodo01','id':0},{'nodo':'nodo02','id':1},{'nodo':'nodo01','id':1,'extra':1},{'nodo':'nodo01','id':1,'valor':float('nan')}]:
            with self.subTest(dato=dato):self.assertEqual(s.almacenar(self.db,'nodo01-1',dato)[0],400)
    def test_identidad_coherente(self):
        self.assertEqual(s.almacenar(self.db,'nodo01-8',{'nodo':'nodo01','id':9})[0],400)
    def test_reenvios_concurrentes(self):
        # Inicializa esquema antes de las peticiones simultáneas.
        s.almacenar(self.db,'nodo01-1',{'nodo':'nodo01','id':1})
        with ThreadPoolExecutor(max_workers=4) as pool:
            codes=list(pool.map(lambda _:s.almacenar(self.db,'nodo01-4',{'nodo':'nodo01','id':4})[0],range(8)))
        self.assertEqual(codes.count(201),1);self.assertEqual(codes.count(200),7)
    def test_http_contrato(self):
        server=s.ThreadingHTTPServer(('127.0.0.1',0),s.Handler);server.db=self.db
        t=threading.Thread(target=server.serve_forever,daemon=True);t.start();base=f'http://127.0.0.1:{server.server_port}'
        try:
            with urllib.request.urlopen(base+'/medicion') as response:self.assertEqual(json.load(response)['source'],'simulated')
            req=urllib.request.Request(base+'/eventos',data=b'{"nodo":"nodo01","id":7}',headers={'Content-Type':'application/json','Idempotency-Key':'nodo01-7'})
            with urllib.request.urlopen(req) as response:self.assertEqual((response.status,json.load(response)['ack']),(201,'nodo01-7'))
            for url,body,headers,status in [('/falta',None,{},404),('/eventos',b'{',{'Content-Type':'application/json'},400),('/eventos',b'{}',{},415),('/eventos',b'x'*1025,{'Content-Type':'application/json'},413)]:
                req=urllib.request.Request(base+url,data=body,headers=headers)
                with self.assertRaises(urllib.error.HTTPError) as error:urllib.request.urlopen(req)
                self.assertEqual(error.exception.code,status)
        finally:server.shutdown();server.server_close();t.join()

if __name__=='__main__':unittest.main()
