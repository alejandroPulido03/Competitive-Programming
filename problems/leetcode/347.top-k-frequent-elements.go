package main

import "sort"

/*
 * @lc app=leetcode id=347 lang=golang
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
func topKFrequent(nums []int, k int) []int {
    vals := make(map[int]int)

	for _, n := range nums{
		vals[n]++
	} //n
	keys := make([]int, 0)

	for k := range vals{
		keys = append(keys, k)
	} //m

	sort.Slice(keys, func(i, j int) bool { return vals[keys[i]] > vals[keys[j]] }) //n + mlogm

	return keys[:k]

}
// @lc code=end

