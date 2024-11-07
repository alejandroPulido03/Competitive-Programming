package main

/*
 * @lc app=leetcode id=98 lang=golang
 *
 * [98] Validate Binary Search Tree
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
 func isValidBST(root *TreeNode) bool {
	nodes := make([]int, 0)
	tour(root, &nodes)
	for i := 1; i < len(nodes); i++{
		if nodes[i] <= nodes[i-1]{
			return false
		}
	}

	return true
}

func tour(root *TreeNode, nodes* []int){
	if(root.Left != nil){
		tour(root.Left, nodes)
	}
	*nodes = append(*nodes, root.Val)
	if(root.Right != nil){
		tour(root.Right, nodes)
	}
}


// @lc code=end

