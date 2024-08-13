#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#


# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        nums_len = len(nums)
        l = 0
        r = nums_len - 1
        last = nums[r]
        mid = (l + r) // 2
        while l < r:
            if nums[mid] > nums[(mid + 1) % nums_len]:
                return nums[(mid + 1) % nums_len]
            if last > nums[mid]:
                r = mid
            else:
                l = mid
            last = nums[mid]
            mid = (l + r) // 2
        return nums[mid]


# @lc code=end
