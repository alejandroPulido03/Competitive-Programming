/*
 * @lc app=leetcode id=152 lang=golang
 *
 * [152] Maximum Product Subarray
 */
package main


// @lc code=start

 func maxProduct(nums []int) int {
    var max_val float64 = -11
	var m float64 = 0
	

	for i := 0; i < len(nums); i++ {
		var b float64 = 1
		for j := i; j < len(nums); j++ {
			m = b * float64(nums[j])
			if m <=  2147483647{
				max_val = max(max_val, m)
				b = m
			}else{
				b = -11
			}
		}
	}

	return int(max_val)
 }

// @lc code=end
