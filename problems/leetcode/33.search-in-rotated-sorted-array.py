#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#


# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums_len = len(nums)
        l = 0
        r = nums_len - 1
        last = nums[r]
        mid = (l + r) // 2
        min__num = -1
        while l < r:
            if nums[mid] > nums[(mid + 1) % nums_len]:
                min__num = (mid + 1) % nums_len
            if last > nums[mid]:
                r = mid - 1
            else:
                l = mid + 1
            last = nums[mid]
            mid = (l + r) // 2

        min__num = mid if min__num == -1 else min__num

        if nums[min__num] < target:
            return self.binary_s(min__num, nums_len - 1, target, nums)
        else:
            return self.binary_s(0, min__num - 1, target, nums)

    def binary_s(self, l, r, target, nums):
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        return -1


# 1 2 4 5
# 1 2
# @lc code=end
