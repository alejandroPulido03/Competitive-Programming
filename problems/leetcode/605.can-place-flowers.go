/*
 * @lc app=leetcode id=605 lang=golang
 *
 * [605] Can Place Flowers
 */
package main

// @lc code=start
func canPlaceFlowers(flowerbed []int, n int) bool {
	count_spaces := 0
	for i := 0; i < len(flowerbed); i++ {
		if flowerbed[i] == 0 {
			if (i == 0 || flowerbed[i-1] != 1) && (i == len(flowerbed)-1 || flowerbed[i+1] != 1) {
				flowerbed[i] = 1
				count_spaces++
			}
		}
	}

	return count_spaces >= n
}

// @lc code=end
