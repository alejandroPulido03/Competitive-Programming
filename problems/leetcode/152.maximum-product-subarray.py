#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        last = [1 for _ in nums]
        dp = last
        maxVal = float("-inf")

        for i in range(len(nums)):
            for j in range(len(nums) - i):
                if j == 0:
                    dp[i] = nums[i]
                else:
                    dp[i] = nums[i + j] * last[i]
                maxVal = max(maxVal, dp[i])
            last = dp
        return maxVal

        


# @lc code=end
