package main

/*
 * @lc app=leetcode id=105 lang=golang
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
/*
 * Definition for a binary tree node.
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}
*/


func buildTree(preorder []int, inorder []int) *TreeNode {

	inorder_ind := make(map[int]int)

	for i:=0; i < len(inorder); i++{
		inorder_ind[inorder[i]] = i
	}

	root := &TreeNode{
		Val: preorder[0],
	}

	i := 0
	b_t(root, inorder_ind, preorder, &i, 0, len(preorder)-1)

	return root
	
}

func b_t(root *TreeNode, in map[int]int, pr []int, i *int, min, max int){

	if  in[root.Val] > min{
		// Put the next that in[i+a] < in[i]
		*i++
		root.Left = &TreeNode{ Val: pr[*i] }

		b_t(root.Left, in, pr, i, min, in[root.Val] - 1)
	}

	if in[root.Val] < max{
		// Put the next that in[i+b] > in[i]
		*i++
		root.Right = &TreeNode{ Val: pr[*i] }

		b_t(root.Right, in, pr, i, in[root.Val] + 1, max)
	}
	
}

// @lc code=end

