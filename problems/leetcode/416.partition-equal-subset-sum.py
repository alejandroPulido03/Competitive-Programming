#
# @lc app=leetcode id=416 lang=python3
#
# [416] Partition Equal Subset Sum
#

# @lc code=start


class Solution:
    def canPartition(self, nums) -> bool:
        if sum(nums) % 2 != 0:
            return False

        dp = set()
        dp.add(0)

        target = sum(nums) // 2
        for i in range(len(nums)):
            if nums[i] == target:
                return True
            newDp = dp.copy()
            for elem in dp:
                if elem + nums[i] == target:
                    return True
                if elem + nums[i] < target:
                    newDp.add(elem + nums[i])
            dp = newDp
        
        return target in dp



# @lc code=end
