package main

type TreeNode struct {
	Val   int
    Left  *TreeNode
    Right *TreeNode
}

/*
 * @lc app=leetcode id=235 lang=golang
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

 func lowestCommonAncestor2(root, p, q *TreeNode) *TreeNode {
	if (root.Val >= p.Val && root.Val <= q.Val) || (root.Val <= p.Val && root.Val >= q.Val){
		return root
	} else if (root.Val > p.Val){
		return lowestCommonAncestor(root.Left, p, q)
	}else{
		return lowestCommonAncestor(root.Right, p, q)
	}
}

// @lc code=end

