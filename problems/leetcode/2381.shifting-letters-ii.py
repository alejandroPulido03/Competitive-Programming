#
# @lc app=leetcode id=2381 lang=python3
#
# [2381] Shifting Letters II
#

# @lc code=start
class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:

        # ***** Prefix Sum ******
        prefix_sum = [0 for _ in range(len(s) + 1)]
        res = ""

        for query in shifts:
            i = query[0]
            j = query[1]
            val = (query[2] * 2) - 1  # 1 || -1
            prefix_sum[i] += val
            prefix_sum[j + 1] -= val

        val = 0
        for i in range(len(s)):
            val += prefix_sum[i]
            diff = ((ord(s[i]) + val - 97) % 26) + 97
            res += chr(diff)

        return res


# @lc code=end
