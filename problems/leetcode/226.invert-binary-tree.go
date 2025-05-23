package main

/*
 * @lc app=leetcode id=226 lang=golang
 *
 * [226] Invert Binary Tree
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
func invertTree(root *TreeNode) *TreeNode {
	if root != nil{
		temp:= root.Left
		root.Left = root.Right
		root.Right = temp
		invertTree(root.Left)
		invertTree(root.Right)
	}
	return root
}

// @lc code=end

