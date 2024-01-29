#
# @lc app=leetcode id=402 lang=python3
#
# [402] Remove K Digits
#

# @lc code=start
class Solution:
    import sys
    sys.set_int_max_str_digits(100001)

    def removeKdigits(self, num: str, k: int) -> str:

        min_num = ""
        for digit in num:
            while min_num and k > 0 and min_num[-1] > digit:
                min_num = min_num[:-1]
                k -=1

            min_num += digit
    
        if k > 0:
            min_num = min_num[:-k]
    
        return str(int(min_num or "0"))
    

        


# @lc code=end
