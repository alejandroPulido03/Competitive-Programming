#
# @lc app=leetcode id=399 lang=python3
#
# [399] Evaluate Division
#


# @lc code=start


class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        adj = {}

        for i, (a, b) in enumerate(equations):
            if a not in adj:
                adj[a] = {}

            if b not in adj:
                adj[b] = {}

            adj[a][b] = values[i]
            adj[b][a] = 1 / values[i]

        res = []
        for c, d in queries:
            val = self.solveQueries(c, d, adj, {})
            res.append(max(val, -1))
        return res

    def solveQueries(self, c, d, adj, visited):
        visited[c] = True
        if c in adj:
            for v in adj[c]:
                w = adj[c][v]
                if v == d:
                    return w
                elif v not in visited:
                    val = self.solveQueries(v, d, adj, visited)
                    if val != -1:
                        return w * val

        return -1


# @lc code=end
