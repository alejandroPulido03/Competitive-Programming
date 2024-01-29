#
# @lc app=leetcode id=238 lang=python3
#
# [238] Product of Array Except Self
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
            [i] = [0... i - 1] * [i + 1 ... n]
            Prefix product
            [i] = prod([i-1]) * [i-1]
        """
        res = [1 for _ in range(len(nums))]
        pref = 1
        suff = 1
        for i in range(len(nums)):
            j = len(nums) - 1 - i
            if i > 0:
                pref *= nums[i - 1]
                suff *= nums[j + 1]
            
            res[i] *= pref
            res[j] *= suff
            
        return res


# @lc code=end
