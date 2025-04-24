package main

import "fmt"

/*
 * @lc app=leetcode id=230 lang=golang
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    var last_val int
	getMinK(&last_val, &k, root)
	return last_val
}

func getMinK(last_value *int, k *int, root *TreeNode){
	if root != nil{
		getMinK(last_value, k, root.Left)
		if *k > 0{
			fmt.Println(root.Val)
			*last_value = root.Val
			*k--
		}
		getMinK(last_value, k, root.Right)
	}
	
}
// @lc code=end

