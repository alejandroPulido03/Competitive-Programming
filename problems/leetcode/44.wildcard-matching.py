#
# @lc app=leetcode id=44 lang=python3
#
# [44] Wildcard Matching
#

# @lc code=start
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[True for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]
        s = " " + s
        p = " " + p
        ast = 0
        for i in range(len(s)):
            for j in range(len(p)):
                if i == 0 and j > 0:
                    dp[i][j] = p[j] == "*" and dp[i][j - 1]
                elif j == 0 and i > 0:
                    dp[i][j] = False
                elif p[j] == "*":
                    ast += 1
                    if j - ast <= i :
                        dp[i][j] = dp[i-1][j-1] or dp[i-1][j] or dp[i][j - 1]
                    else:
                        dp[i][j] = dp[i-1][j-1] or dp[i][j - 1]
                elif s[i] == p[j] or p[j] == "?":
                    dp[i][j] = dp[i-1][j-1]
                else: # s[i] != p[j]
                    dp[i][j] = False
        
        return dp[-1][-1]

# @lc code=end
