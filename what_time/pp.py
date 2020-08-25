
def pop_max(lst):
  global custos
  index_maior = 0
  maior = 0
  for i, e in enumerate(lst):
    if custos[e] < maior:
      maior = custos[e]
      index_maior = i
  return lst.pop(index_maior)


from collections import defaultdict

custos = {}
apontados = set()
todos = set()
nodos = defaultdict(list)
pq = []
for i, line in enumerate(open('input').readlines()):
  if i == 0:
    _, _, n = line.split(' ')
    continue
  raw1, _, raw2 = line.split(' ')
  p1, t1 = raw1.split('_')
  p2, t2 = raw2.split('_')
  t1 = int(t1)
  t2 = int(t2)
  nodos[p1].append(p2) 
  custos[p1] = t1
  custos[p2] = t2

  apontados.add(p2)
  todos.add(p1)
  todos.add(p2)
  # print(p1, t1, p2, t2)

n = int(n)
roots = []
for nn in todos:
  if nn not in apontados:
    roots.append(nn)

fila = roots
processando = []
timestamp = 0
while True:
  while len(processando) < n and len(fila):
    current = pop_max(fila) # TODO: pop_min(fila)
    processando.append((current, custos[current]))
  print(processando)
  menor = 1000000000
  nome_menor_custo = ''
  for (nome, custo) in processando:
    if custo < menor:
      menor = custo
      nome_menor_custo = nome

  processando = [(nome, custo - menor) for (nome, custo) in processando if nome != nome_menor_custo]
  timestamp += menor
  for node in nodos[nome_menor_custo]:
    fila.append(node)

  if len(fila) == 0 and len(processando) == 0:
    break

print(timestamp)

