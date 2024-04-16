#
# @lc app=leetcode id=2493 lang=python3
#
# [2493] Divide Nodes Into the Maximum Number of Groups
#

# @lc code=start
class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]

        for edge in edges:
            a, b = map(lambda x: x - 1, edge)
            graph[a].append(b)
            graph[b].append(a)

        
        visited = [False] * n
        queue = [0]
        groups = [[0]]
        for v in visited:
            visited = True
            while(queue):
                top = queue.pop(0)
                for adj in graph[top]:
                    pass






# @lc code=end
