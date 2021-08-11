from Grafo import grafo
import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict 

BRANCO = 0
CINZA = 1
PRETO = 2
VERMELHO = 3
AZUL = 4

def dfs(G,no_initial):
    dis = defaultdict(list)
    for no in G.getNodes():
        dis[no]=0

    visited = defaultdict(list)
    for no in G.getNodes():
        visited[no]=BRANCO

    if visited[no_initial]==BRANCO:
        dis[no_initial]=0
        dfs_visit(G,no_initial,visited,dis)
    for no in G.getNodes():
        if visited[no]==BRANCO:
            dis[no]=0    
    print("distancias -> ",dis)

def dfs_visit(G,v,visited,dis):
    visited[v]=CINZA
    print("vértice ",v)
    for u in G.getNeighbors(v):
        if visited[u] ==BRANCO:
            
            visited[u]=CINZA
            dis[u] = dis[v]+1
            dfs_visit(G,u,visited,dis)  
        
    visited[v]=PRETO

            
if __name__ == '__main__':
    g = grafo.Graph()
    g.addMultipleNodes(['a','b','c','d','e'])
    g.addEdge('a','b')
    g.addEdge('a','c')
    g.addEdge('a','d')
    nx.draw(g.graph, with_labels=True)
    plt.show() 

    dfs(g,'d')

    