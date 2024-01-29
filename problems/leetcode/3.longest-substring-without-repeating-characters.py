#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = {}
        startPointer = 0
        finishPointer = 0
        maxStrLen = 0
        for i in range(len(s)):
            if s[i] not in chars or chars[s[i]] < startPointer:
                chars[s[i]] = i
            else:
                maxStrLen = max(maxStrLen, finishPointer - startPointer)
                startPointer = chars[s[i]] + 1
                chars[s[i]] = i

            finishPointer = i + 1
            maxStrLen = max(maxStrLen, finishPointer - startPointer)

        return maxStrLen

# @lc code=end
