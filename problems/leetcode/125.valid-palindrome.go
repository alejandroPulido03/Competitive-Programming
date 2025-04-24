package main

import (
	"regexp"
	"strings"
)

/*
 * @lc app=leetcode id=125 lang=golang
 *
 * [125] Valid Palindrome
 */

// @lc code=start
func isPalindrome(s string) bool {
    s = strings.ToLower(s)
	s = strings.Replace(s, " ", "", -1)
	s = regexp.MustCompile(`[^a-z0-9 ]+`).ReplaceAllString(s, "")
	
	for i:=0; i < len(s) / 2; i++{
		if s[i] != s[len(s) - i - 1]{
			return false
		}
	}
	

	return true

}
// @lc code=end

