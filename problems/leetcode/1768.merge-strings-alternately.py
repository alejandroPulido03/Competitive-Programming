#
# @lc app=leetcode id=1768 lang=python3
#
# [1768] Merge Strings Alternately
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        new_word = ""

        for i in range(min(len(word1), len(word2))):
            new_word += word1[i] + word2[i]
        
        new_word += word1[i + 1:] + word2[i + 1:]

        return new_word

        
# @lc code=end

