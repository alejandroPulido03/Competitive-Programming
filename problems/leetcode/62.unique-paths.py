#
# @lc app=leetcode id=62 lang=python3
#
# [62] Unique Paths
#

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for m_i in range(m + 1):
            for n_i in range(n + 1):
                if n_i == 1 or m_i == 1:
                    dp[m_i][n_i] = 1
                else:
                    dp[m_i][n_i] = dp[m_i][n_i - 1] + dp[m_i - 1][n_i]
        return dp[m][n]


# @lc code=end
