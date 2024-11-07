package main

import "strconv"

/*
 * @lc app=leetcode id=91 lang=golang
 *
 * [91] Decode Ways
 */

// @lc code=start
func numDecodings(s string) int {
	if s[0] == '0'{
		return 0
	}

    f_2 := 1
	f_1 := 1

	for i := 1; i < len(s); i++ {
		comb := f_1
		if v,_ := strconv.Atoi(s[i-1:i]); s[i] != '0' &&  v <= 26{
			comb += f_2
		}
		f_2 = f_1
		f_1 = comb
		
	}

	return f_1
}
// @lc code=end

