#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#


# @lc code=start
class Solution:
    def maxProduct(self, nums) -> int:
        max_val = -11
        m = 0
        for i in range(len(nums)):
            b = 1
            for j in range(i, len(nums)):
                m = b * nums[j]
                max_val = max(max_val, m)
                b = m
        return max_val


# @lc code=end
