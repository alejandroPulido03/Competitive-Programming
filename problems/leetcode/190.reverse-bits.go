package main

/*
 * @lc app=leetcode id=190 lang=golang
 *
 * [190] Reverse Bits
 */

// @lc code=start
func reverseBits(num uint32) uint32 {
	var new_num uint32

	for i := 0; i < 31; i++{
		new_num |= (num % 2)
		new_num <<= 1
		num >>= 1
	}
	new_num |= (num % 2)

	

	return new_num
}
// @lc code=end

