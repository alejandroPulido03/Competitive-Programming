package main

/*
 * @lc app=leetcode id=100 lang=golang
 *
 * [100] Same Tree
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
func isSameTree(p *TreeNode, q *TreeNode) bool {
    return (p == nil && q == nil) || (p != nil && q != nil && p.Val == q.Val && (p.Left == nil && q.Left == nil || p.Left != nil && q.Left != nil && isSameTree(p.Left, q.Left)) && (p.Right == nil && q.Right == nil || p.Right != nil && q.Right != nil && isSameTree(p.Right, q.Right)))
}
// @lc code=end

