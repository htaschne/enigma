from xtree import nodes

arestas = set()

def buildTree(target):
    global arestas
    filhos = []
    for i in range(target.filhos):
        filhos.append(nodes.pop(0))
        arestas.add((target, filhos[-1]))

    for filho in filhos:
        buildTree(filho)

buildTree(nodes.pop(0))

print('digraph {')
for aresta in arestas:
    a, b = aresta
    print('  {}->{}'.format(a.val, b.val))
print('}')
