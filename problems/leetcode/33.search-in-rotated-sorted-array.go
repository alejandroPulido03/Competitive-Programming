package main

/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
func search(nums []int, target int) int {
	k, n := 0, len(nums)-1
	if nums[k] <= nums[n]{
		return bs(nums, k, n, target)
	}else {
		pivot := bs_piv(nums, k, n)
		if target <= nums[n]{
			return bs(nums, pivot + 1, n, target)
		}else {
			return bs(nums, k, pivot, target)
		}
		
	}
}

func bs(nums []int, min, max, target int) int{
	if max >= min{
		mid := (max + min) / 2
		
		if nums[mid] == target{
			return mid
		}else if target < nums[mid]{
			return bs(nums, min, mid-1, target)
		}else{
			return bs(nums, mid+1, max, target)
		}
	}
	return -1
}

func bs_piv(nums []int, min, max int) int{
	n := len(nums)-1
	mid := (max + min) / 2
	if mid+1 == len(nums) || nums[mid] > nums[mid+1]{
		return mid
	}else if nums[mid] < nums[n]{
		return bs_piv(nums, min, mid-1)
	}else{
		return bs_piv(nums, mid+1, max)
	}
}



// @lc code=end

