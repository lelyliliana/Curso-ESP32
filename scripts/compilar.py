"""Compila la referencia sin secretos ni carga física; Python3.10+."""
import argparse,json,subprocess,tempfile,shutil
from pathlib import Path
p=argparse.ArgumentParser();p.add_argument('--cli',default='arduino-cli');p.add_argument('--config');p.add_argument('--unidad',type=int);a=p.parse_args()
r=Path(__file__).resolve().parents[1];items=json.loads((r/'laboratorios/catalogo.json').read_text());errores=[]
with tempfile.TemporaryDirectory(prefix='esp32-curso-') as temp:
 for item in items:
  if a.unidad is not None and item['unidad']!=a.unidad:continue
  src=r/item['sketch'];dest=Path(temp)/src.parent.name
  shutil.copytree(src.parent,dest,ignore=shutil.ignore_patterns('config_local.h','ca_local.h','build'))
  command=[a.cli]
  if a.config:command+=['--config-file',a.config]
  command+=['compile','--fqbn','esp32:esp32:esp32','--warnings','default','--jobs','2',str(dest)]
  result=subprocess.run(command,capture_output=True,text=True)
  print(f"{item['unidad']:02d} {src.parent.name}: {'OK' if result.returncode==0 else 'FALLO'}",flush=True)
  if result.returncode:errores.append(item['unidad']);print((result.stdout+result.stderr)[-9000:],flush=True)
print('Fallos:',errores)
raise SystemExit(bool(errores))
