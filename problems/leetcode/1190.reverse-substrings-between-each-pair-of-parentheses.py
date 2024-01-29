#
# @lc app=leetcode id=1190 lang=python3
#
# [1190] Reverse Substrings Between Each Pair of Parentheses
#

# @lc code=start
class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        newS = s
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            if s[i] == ')':
                f = stack.pop()
                newS = newS[0: f] + newS[i: f: -1] + newS[i: ]
        newS = newS.replace("(", "").replace(")", "")
        return newS
    
    
# @lc code=end

