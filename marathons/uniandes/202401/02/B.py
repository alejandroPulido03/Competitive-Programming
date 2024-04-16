n = int(input())

a = set()
b = 0

graph = [[] for _ in range(n)]
u, v = -1, -1
for _ in range(n - 1):
    u, v = map(lambda x: int(x) - 1, input().split())
    graph[u].append(v)
    graph[v].append(u)


state = True
def dfs(graph, s=0):
    global state
    global a
    global b
    visited = [-1 for _ in range(len(graph))]
    stack = [s]
    edgeTo = [-1 for _ in range(len(graph))]
    while True:
        while stack:
            top = stack[-1]
            if visited[top] == 0:
                if state:
                    a.add(stack.pop())
                else:
                    b += 1
                    stack.pop()
                state = not state
            else:
                visited[top] = 0
                for i in graph[top]:
                    if visited[i] == -1:
                        edgeTo[i] = top
                        stack.append(i)

        if -1 in visited:
            stack = [visited.index(-1)]
        else:
            break

    return edgeTo
    
dfs(graph)


print(len(a) * b - (n - 1))


