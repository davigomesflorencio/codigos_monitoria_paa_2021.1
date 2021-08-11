from Grafo import grafo

import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict 

BRANCO = 0
CINZA = 1
PRETO = 2
VERMELHO = 3
AZUL = 4

def dfs(G):
    cor = defaultdict(list)
    for no in G.getNodes():
        cor[no]=0

    visited = defaultdict(list)
    for no in G.getNodes():
        visited[no]=BRANCO

    for no in G.getNodes():
        if visited[no]==BRANCO:
            cor[no]=VERMELHO
            if dfs_visit(G,no,visited,cor):
                return True
    return False

def dfs_visit(G,v,visited,cor):
    visited[v]=CINZA
    print("vértice ",v)
    for u in G.getNeighbors(v):
        if visited[u] ==BRANCO:
            
            visited[u]=CINZA

            if(cor[v]==VERMELHO):
                cor[u] = AZUL
            else:
                cor[u] = VERMELHO
            dfs_visit(G,u,visited,cor)         
        elif (cor[v] == cor[u]):
            return False
        
    visited[v]=PRETO
    return True

            
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
        print("G é bipartido")
    else:
        print("G não é bipartido")

    

#    print(g.getNodes())
    