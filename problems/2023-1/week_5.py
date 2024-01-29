""" n, m = map(int, input().split(' '))
restrictions = [list(map(int, input().split(' '))) for _ in range(m)]
center = [i for i in range(n + 1)]
for rest in restrictions:
    center[rest[0]] = 0
    center[rest[1]] = 0

center = list(filter(lambda x: x != 0, center))[0]
print(n - 1)
for i in range(1, n + 1):
    if i != center:
        print(f'{center} {i}') """


n, l, r, x = map(int, input().split(' '))
graph = []
edges = []
for i in map(int, input().split(' ')):
    graph.append(i)

for i in range(len(graph)):
    for j in range(i ,len(graph)):
        if r >= abs(graph[i] - graph[j]) >= x:
            
            edges.append(graph[i] + graph[j])

times = 0

edges.sort()


print(edges)
        