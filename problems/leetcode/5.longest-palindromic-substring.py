#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# @lc code=start
class Solution:

    def longestPalindrome(self, s: str) -> str:
        dp = [[0 for _ in range(len(s))] for _ in range(len(s))]
                    
        for k in range(len(s)):
            dp[0][k] = k

        x, y = 0,0
        for j in range(1, len(s)):
            for i in range(len(s) - j):
                if s[i] == s[i + j] and (j == 1 or dp[j - 2][i + 1] == i + j - 1):
                    dp[j][i] = i + j
                else:
                    dp[j][i] = dp[j - 1][i] 
                
                if dp[j][i] - i > y - x:
                    x, y = i, dp[j][i]
        
        return s[x : y + 1]
        # @lc code=end