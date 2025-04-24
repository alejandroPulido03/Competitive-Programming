package main

/*
 * @lc app=leetcode id=128 lang=golang
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
func longestConsecutive(nums []int) int {
	num_map := make(map[int]int, 0)
	visited := make([]bool, len(nums))


	for i, v := range nums{
		num_map[v] = i
	}

	max_val := 0
	
	for i:=0; i < len(visited); i++{
		
		if !visited[i]{

			visited[i] = true

			count := 1
			
			top := nums[i] + 1
			ind, ok := num_map[top]
			for ok && !visited[ind]{
				visited[ind] = true
				
				count++
				top++
				ind, ok = num_map[top]
			}

			back := nums[i] - 1
			ind, ok = num_map[back]
			for ok && !visited[ind]{
				visited[ind] = true
	
				count++
				back--
				ind, ok = num_map[back]
			}
			max_val = max(max_val, count)
			
		}
	}

	return max_val
}
// @lc code=end

