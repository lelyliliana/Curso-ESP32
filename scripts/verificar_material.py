"""Comprueba catálogo y enlaces locales, sin Internet ni placa."""
from pathlib import Path
from urllib.parse import unquote
import json,re
r=Path(__file__).resolve().parents[1];errors=[]
items=json.loads((r/'laboratorios/catalogo.json').read_text())
if sorted(set(x['unidad'] for x in items))!=list(range(24)):errors.append('catalogo incompleto o desordenado')
for x in items:
    p=r/x['sketch']
    if not p.exists():errors.append(str(p)+' ausente')
    if p.stem!=p.parent.name:errors.append(str(p)+' nombre incompatible con Arduino IDE')
    u=r/p.relative_to(r).parts[0]
    for name in ['LABORATORIO.md','SOLUCIONES.md']:
        if not (u/name).is_file():errors.append(str(u/name)+' ausente')
for f in r.rglob('*.md'):
    if '.git' in f.parts:continue
    for link in re.findall(r'\]\(([^\s)]+)',f.read_text(encoding='utf-8')):
        if re.match(r'^(https?:|mailto:|#)',link):continue
        target=unquote(link.split('#')[0].split('?')[0])
        if target and not (f.parent/target).exists():errors.append(str(f.relative_to(r))+': '+target)
print('\n'.join(errors) if errors else 'OK: 24 laboratorios, 26 sketches y enlaces locales')
raise SystemExit(bool(errors))
