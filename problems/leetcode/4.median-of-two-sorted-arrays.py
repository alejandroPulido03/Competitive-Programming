#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        import math as m

        a, b = nums1[m.floor(nums1 // 2) +
                     1], nums1[m.ceil(nums1 // 2)]
        # [1, 5, 8, 10] [3, 4, 6, 11]


# @lc code=end
