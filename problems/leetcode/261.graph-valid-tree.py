import functools


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj = [ [] for _ in range(n) ]
        visited = [False] * n

        for v, u in edges:
            adj[v].append(u)
            adj[u].append(v)
        
        stack = [0]
        
        while len(stack) > 0:
            top = stack.pop()
            visited[top] = True
            father = False
            for v in adj[top]:
                if visited[v]:
                    if father:
                        return False
                    else:
                        father = True
                else:
                    stack.append(v)

        return functools.reduce(lambda x, y: x and y, visited)