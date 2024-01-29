"""
Para encontrar puentes podemos aprovechar la forma en la que estos se ven en un arbol generado por la relación parent de un recorrido DFS.
En este tipo de árbol únicamente tenemos back edges y también es imporante saber que estos back edges solo van a ser entre su misma ramificación, es decir que si un árbol tiene dos o más ramificaciones, los backedges nunca van a pasar de una a la otra, en otras palabras no hay cross-edges. Sabemos que si hay un arco (u, v) y ni v ni sus sucesores tiene un back-edge a u o a sus antecesores el arco (u,v) es puente, puesto que la única forma de que v y sus suscesores
se conecte con el resto del grafo es pasando por u.

Para esto podemos mantener una lista llamada inVert que calcule cuantos vértices pasaron hasta que fue encontrado el vértice actual.
Así mismo podemos mantener otra que se llame minVert y que mantenga el vertice mínimo al que el vértice puede acceder diferente del padre. Esto es importante porque si el minVert de un hijo es mayor que el inVert de el padre significa que todas las conexiones hacia los vertices anteriores al padre desde el hijo o sus sucesores se tienen que hacer pasando por el padre, en otras palabras, el arco entre ese padre y ese hijo es un puente.
"""


visited = []
inVert = []
minVert = []
vert = 0
graph = [
[1,2,4,11],
[0, 2],
[0, 1, 6],
[4],
[3, 0],
[0, 6, 7],
[2, 8, 5],
[5],
[6, 9, 10],
[8, 10],
[9, 8],
[0, 12],
[11]
]
bridges = []

def find_bridges():
    global inVert, visited, minVert, graph
    n = len(graph)
    visited = [False for _ in range(n)]
    inVert = [-1 for _ in range(n)]
    minVert = [-1 for _ in range(n)]

    for i in range(n): #En caso de que el grafo no esté completamente conectado
        if not visited[i]:
            dfs(i)
    return bridges

def dfs(root, parent= -1):
    global vert, inVert, visited, minVert
    vert += 1
    visited[root] = True
    inVert[root] = vert
    minVert[root] = vert
    for v in graph[root]:
        if v != parent: #No se verifica la relacion con el parent ya que queremos conocer la conexion mínima con respecto a los backedges
            if not visited[v]: #Necesitamos sacar el min de v para comparar
                dfs(v, root)
                minVert[root] = min(minVert[root], minVert[v])
                if(minVert[v] > inVert[root]):
                    bridges.append((v, root))
            else: # Ya tiene un backedge por lo que ya habia sido visitado 
                minVert[root] = min(minVert[root], inVert[v])

print(find_bridges())
