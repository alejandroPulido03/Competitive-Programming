n = int(input())

input()

final = -1
init = -1

adj = [[] for _ in range(n*n)]
matrix = []
for i in range(n):
    matrix.append(input()[1:-1])


def add_edges(i, j, adj, n):
    v = (n*i) + j
    for a in range(-1, 2):
        for b in range(-1, 2):
            if (a != 0 or b != 0) and 0 <= i+a < n and 0 <= j+b < n:
                u = (n*(i+a)) + (j + b)
                if matrix[i+a][j+b] != '*':
                    adj[v].append(u)


for i in range(n):
    row = matrix[i]
    for j in range(n):
        if row[j] == 'F':
            final = (n * i) + j
        if row[j] == 'i':
            init = (n * i) + j
        if row[j] != '*':
            add_edges(i, j, adj, n)


input()

marked = [False] * n*n


def bfs(v, target, steps=0):
    queue = [(v, 0)]
    while (len(queue) > 0):
        top, depth = queue[0]
        if marked[top]:
            queue.pop(0)
        else:
            marked[top] = True
            if top == target:
                return f"+{depth - 1}"
            for u in adj[top]:
                if not marked[u]:
                    queue.append((u, depth + 1))
    return "-1"


print(bfs(init, final))
