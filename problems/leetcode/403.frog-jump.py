#
# @lc app=leetcode id=403 lang=python3
#
# [403] Frog Jump
#

# @lc code=start
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        dp = [set() for _ in stones]
        dp[0] = {0}
        for i in range(len(stones)):
            k = dp[i]
            for j in range(i + 1, len(stones)):
                jump = stones[j] - stones[i]
                if jump in k or jump + 1 in k or jump - 1 in k:
                    dp[j].add(jump)
        return len(dp[-1]) != 0
# @lc code=end
