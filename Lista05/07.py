from Grafo import grafo
import networkx as nx
import matplotlib.pyplot as plt
from collections import defaultdict 
from collections import deque 
import numpy as np

INF = 999

def floyd(G,nodes):
    dist = list(map(lambda p: list(map(lambda q: q, p)), G))

    for r in range(nodes):
        for p in range(nodes):
            for q in range(nodes):
                dist[p][q] = min(dist[p][q], dist[p][r] + dist[r][q])
    
    return sol(dist,nodes)

# Printing the output
def sol(dist,nodes):
    res = 0
    for p in range(nodes):
        for q in range(nodes):
            if(dist[p][q]!=INF):
                res =max(res,dist[p][q]) 
            if(dist[p][q] == INF):
                print("INF", end=" ")
            else:
                print(dist[p][q], end="  ")
        print(" ")
    
    return res

def constructMatrix(G,nodes):
    
    matrix = np.zeros( (nodes, nodes) )
    for i in range(nodes):
        for j in range(nodes):
            if (i+1,j+1) in G.graph.edges():
                matrix[i][j]=1
            else:        
                matrix[i][j]=INF
    return matrix

            
if __name__ == '__main__':
    g = grafo.Graph()
    g.addMultipleNodes([1,2,3,4,5,6,7])
    g.addEdge(1,2)
    g.addEdge(1,3)
    g.addEdge(1,4)
    # g.addEdge(2,4)
    g.addEdge(4,5)
    g.addEdge(5,6)
    g.addEdge(1,7)
    nx.draw(g.graph, with_labels=True)
    plt.show() 

    matrix = constructMatrix(g,g.getLenNodes())
    
    print("Diametro ",floyd(matrix,g.getLenNodes()))

    

#    print(g.getNodes())
    