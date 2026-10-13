"""Cliente para API LED: python peticion.py http://IP/api/led --activo true"""
import argparse,json,urllib.request,urllib.error
p=argparse.ArgumentParser();p.add_argument('url');p.add_argument('--activo',choices=['true','false']);p.add_argument('--invalido',action='store_true');a=p.parse_args()
if a.invalido:body={'activo':'true'}
elif a.activo is not None:body={'activo':a.activo=='true'}
else:body=None
request=urllib.request.Request(a.url,data=None if body is None else json.dumps(body).encode(),headers={'Content-Type':'application/json'},method='GET' if body is None else 'PUT')
try:
 with urllib.request.urlopen(request,timeout=5) as response:print(response.status,response.read().decode())
except urllib.error.HTTPError as e:print(e.code,e.read().decode())
except urllib.error.URLError as e:print('Transporte:',e.reason);raise SystemExit(1)
