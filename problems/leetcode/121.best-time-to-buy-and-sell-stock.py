#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        maxVal = 0
        diff = 0
        # Reverse iterator
        for i in range(n - 1, -1, -1):
            if prices[i] > maxVal:
                maxVal = prices[i]
            elif maxVal - prices[i] > diff:
                diff = maxVal - prices[i]
        return diff
# @lc code=end
