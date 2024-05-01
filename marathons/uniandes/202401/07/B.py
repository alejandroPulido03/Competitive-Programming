m, n, k = map(int, input().split())

adj = [[] for _ in range(n*m)]
matrix = []
for i in range(m):
    matrix.append(input())


views = [0] * n * m


def add_edges(i, j, adj, n):
    v = (n*i) + j
    for a in range(-1, 2):
        for b in range(-1, 2):
            if (a != 0 or b != 0) and abs(a) != abs(b) and 0 <= i+a < m and 0 <= j+b < n:
                u = (n*(i+a)) + (j + b)
                if matrix[i+a][j+b] != '*':
                    adj[v].append(u)
                else:
                    views[v] += 1


empty = []
for i in range(m):
    row = matrix[i]
    for j in range(n):
        if row[j] != '*':
            add_edges(i, j, adj, n)
            empty.append((n*i) + j)


marked = [False] * n * m
components = [-1] * n * m


def bfs(v, comp):
    queue = [v]
    vi = 0
    while (len(queue) > 0):
        top = queue[0]
        if components[top] == -1:
            components[top] = comp
            vi += views[top]
        if marked[top]:
            queue.pop(0)
        else:
            marked[top] = True
            for u in adj[top]:
                if not marked[u]:
                    queue.append(u)
    return vi


comp = 0
components_views = []

for i in empty:
    if not marked[i]:
        vi = bfs(i, comp)
        components_views.append(vi)
        comp += 1

for _ in range(k):
    i, j = map(lambda i: int(i) - 1, input().split())
    v = n*i + j
    print(components_views[components[v]])
