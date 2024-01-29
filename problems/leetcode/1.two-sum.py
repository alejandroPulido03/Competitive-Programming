#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diff = {}
        for i in range(len(nums)):
            if target - nums[i] in diff:
                return [diff[target - nums[i]], i]
            else:
                diff[nums[i]] = i
# @lc code=end

