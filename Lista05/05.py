from Grafo import grafo
import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict 
from collections import deque 

BRANCO = 0
CINZA = 1
PRETO = 2

def dfs(G):
    visited = defaultdict(list)
    for no in G.getNodes():
        visited[no]=BRANCO
    for no in G.getNodes():
        if visited[no]==BRANCO:
            if dfs_visit(G,no,visited):
                return True
    return False

def dfs_visit(G,v,visited):
    pilha = deque()
    pilha.append(v)
    visited[v] = PRETO
    print("no atual -> ",v)
    while len(pilha)!=0:
        ult = pilha.pop()
        if visited[ult]==BRANCO:
            visited[ult]=CINZA
        for i in G.getNeighbors(ult):
            print("no ",ult,"vizinho -> ",i)
            if visited[i]==BRANCO:
                pilha.append(i)
            if visited[i]==CINZA:
                return True
    return False

            
if __name__ == '__main__':
    g = grafo.Graph()
    g.addMultipleNodes(['a','b','c','d'])
    g.addEdge('a','b')
    g.addEdge('a','c')
    g.addEdge('a','d')
    # g.addEdge('b','d')
    nx.draw(g.graph, with_labels=True)
    plt.show() 
    if(dfs(g)):
        print("Tem ciclo em G")
    else:
        print("Não tem ciclo em G")
    
    