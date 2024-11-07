package main

/*
 * @lc app=leetcode id=236 lang=golang
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	tour := make([]*TreeNode, 0)
	eulerTour(root, &tour)
	parents := make(map[int]int)

	searching := -1
	for _, n := range tour{
		if searching == -1{
			parents[n.Val] = 0
		}
		if searching >= 2{
			_, ok := parents[n.Val]
			if ok {
				return n
			}
		}

		if p.Val == n.Val || q.Val == n.Val{
			searching++
		}
			
	}

	return root

}

func eulerTour(node *TreeNode, tour *[]*TreeNode){
	if node != nil{
		*tour = append(*tour, node)
		eulerTour(node.Left, tour)
		eulerTour(node.Right, tour)
		*tour = append(*tour, node)
	}
}
// @lc code=end

