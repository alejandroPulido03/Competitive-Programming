/*
 * @lc app=leetcode id=235 lang=golang
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */
package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	ancestorsP := make(map[int]*TreeNode)
	ancestorsQ := make([]*TreeNode, 0)

	findAncestors(ancestorsP, root, p)
	findAncestorsList(ancestorsQ, root, q)

	var lca *TreeNode
	for _, k := range ancestorsQ {
		fmt.Println(k)
		if ancestorsP[k.Val] == k {
			lca = k
			return lca
		}
	}

	return root
}

func findAncestors(ancestorsMap map[int]*TreeNode, root, target *TreeNode) bool {
	if root.Val == target.Val {
		ancestorsMap[root.Val] = root
		return true
	} else if root != nil && ((root.Left != nil && findAncestors(ancestorsMap, root.Left, target)) || (root.Right != nil && findAncestors(ancestorsMap, root.Right, target))) {
		ancestorsMap[root.Val] = root
		return true
	} else {
		return false
	}
}

func findAncestorsList(ancestorsList []*TreeNode, root, target *TreeNode) bool {
	if root.Val == target.Val {
		ancestorsList = append(ancestorsList, root)
		return true
	} else if root != nil && ((root.Left != nil && findAncestorsList(ancestorsList, root.Left, target)) || (root.Right != nil && findAncestorsList(ancestorsList, root.Right, target))) {
		ancestorsList = append(ancestorsList, root)
		return true
	} else {
		return false
	}
}

// @lc code=end
