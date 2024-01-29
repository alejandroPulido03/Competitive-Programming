#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        partialMaxSum = 0
        betterMaxSum = float("-inf")

        for i in range(len(nums)):
            currSum = max(nums[i], partialMaxSum + nums[i])
            partialMaxSum = currSum
            betterMaxSum = max(betterMaxSum, partialMaxSum)

        return betterMaxSum

# @lc code=end
