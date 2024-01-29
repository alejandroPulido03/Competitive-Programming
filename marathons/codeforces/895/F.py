def solve():
    n = int(input())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    graph = [[] for _ in range(n)]

    for i in range(n):
        graph[a[i] - 1].append(i)

    
    visited = set()
    order = []

    while (len(visited) != n):
        for i in range(n):
            if i not in visited:
                dfs(visited, graph, i, order)

    print(" ".join(list(map(str, order))))




def dfs(visited, graph, node, order):
    if node not in visited:
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour, order)
        order.append(node + 1)



t = int(input())

for _ in range(t):
    
    solve()

