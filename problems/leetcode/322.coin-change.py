#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#

# @lc code=start
class Solution:
    def coinChange(self, c: list, amount: int) -> int:
        c.insert(0, 0)
        dp = [[0 for _ in c] for _ in range(amount + 1)]
        
        for a in range(amount + 1):
            for i in range(len(c)):
                if a > 0:
                    if i == 0:
                        dp[a][i] = float("inf")
                    else:
                        if a >= c[i]:
                            dp[a][i] = min(1 + dp[a - c[i]][i], 1 + dp[a - c[i]][i - 1], dp[a][i - 1]) 
                        else:
                            dp[a][i] = dp[a][i - 1]
        
        return dp[-1][-1] if dp[-1][-1] < float("inf") else -1 
# @lc code=end

