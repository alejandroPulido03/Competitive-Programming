/*
 * @lc app=leetcode id=1431 lang=golang
 *
 * [1431] Kids With the Greatest Number of Candies
 */
package main

// @lc code=start
func kidsWithCandies(candies []int, extraCandies int) []bool {

	max_val := 0
	for _, candy_cant := range candies {
		max_val = max(candy_cant, max_val)
	}

	res := make([]bool, len(candies))
	for i, candy_cant := range candies {
		res[i] = candy_cant+extraCandies >= max_val
	}

	return res
}

// @lc code=end
