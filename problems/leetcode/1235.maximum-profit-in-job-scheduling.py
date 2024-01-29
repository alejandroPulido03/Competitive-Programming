#
# @lc app=leetcode id=1235 lang=python3
#
# [1235] Maximum Profit in Job Scheduling
#

# @lc code=start
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        schedule = [[startTime[i], endTime[i], profit[i]] for i in range(len(startTime))]
        schedule.sort(key= lambda sch : sch[1])
        dp = [0 for _ in range(len(schedule) + 1)]

        for i in range(1, len(schedule) + 1):
            dp[i] = max(dp[i - 1], schedule[i - 1][2] + dp[self.getNonOverlaped(i - 1, schedule) + 1])

        
        return dp[-1]
    
    def getNonOverlaped(self, ind, sch):
        start = sch[ind][0]
        for i in range(ind - 1, -1, -1):
            if sch[i][1] <= start:
                return i
        return -1
    
# @lc code=end

