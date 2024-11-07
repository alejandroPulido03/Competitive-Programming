package main

/*
 * @lc app=leetcode id=213 lang=golang
 *
 * [213] House Robber II
 */

// @lc code=start
func rob(nums []int) int {
	n := len(nums)

	if n > 2{
		dp_i := make([]int, n)

		dp_i[0] = nums[0]
		dp_i[1] = max(nums[1], nums[0])
		for i := 2; i<n-1;i++{
			dp_i[i] = max(dp_i[i-1], nums[i] + dp_i[i-2])
		}

		dp_f := make([]int, n)

		dp_f[1] = nums[1]
		dp_f[2] = max(nums[2], nums[1])
		for i := 3; i<n;i++{
			dp_f[i] = max(dp_f[i-1], nums[i] + dp_f[i-2])
		}
		

		return max(dp_i[n-2], dp_f[n-1])
	}else if n == 2{
		return max(nums[0], nums[1])
	}else {
		return nums[0]
	}
	
}
// @lc code=end

