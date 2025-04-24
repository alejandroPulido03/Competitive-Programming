package main

import "fmt"

/*
 * @lc app=leetcode id=133 lang=golang
 *
 * [133] Clone Graph
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */

type Node struct {
	Val int
	Neighbors []*Node
} 



func cloneGraph(node *Node) *Node {
	if node != nil{
		edges := make([][2]int, 0)
        var visited [101]bool
		getEdges(node, &edges, &visited)
		nodes := make(map[int]*Node, 0)
		nodes[node.Val] = newNode(node.Val)
	

	for _, e := range edges{
		v, u := e[0], e[1]
		if _, ok := nodes[v]; !ok{
			nodes[v] = newNode(v)
		}
		if _, ok := nodes[u]; !ok{
			nodes[u] = newNode(u)
		}
		nodes[v].Neighbors = append(nodes[v].Neighbors, nodes[u])
	}

		return nodes[node.Val]
	}
	return nil
}

func newNode(val int) *Node{
	return &Node{
		val,
		make([]*Node, 0),
	}
}

func getEdges(node *Node, edges *[][2]int, visited *[101]bool){
    fmt.Println(node.Val, visited[node.Val])
	if !visited[node.Val]{
		visited[node.Val] = true
		for _, n := range node.Neighbors{
			fmt.Println(n.Val)
			*edges = append(*edges, [2]int{node.Val, n.Val})
			getEdges(n, edges, visited)
		}
	}
}


