package main

import (
	"math"
)

type ListNode struct {
    Val int
    Next *ListNode
}

/*
 * @lc app=leetcode id=23 lang=golang
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

const INF int = 10001

type listHeap struct {
	list *ListNode
	next int
}

type indexedMinPq struct{
	heap []*listHeap
}

func mergeKLists(lists []*ListNode) *ListNode {

	pq := indexedMinPq{make([]*listHeap, 0)}
	masterList := &ListNode{}
	next := masterList
	for _, n := range lists{
		pq.add(n)
	}

	
	for few := pq.pop(); few != nil; few = pq.pop(){
		next.Next = &ListNode{Val: few.Val}
		next = next.Next
	}

	return masterList.Next
}

func (minPq *indexedMinPq) pop() *ListNode{
	if len(minPq.heap) > 0 {
		first := minPq.heap[0]
		val := first.list
		if first.list == nil{
			return nil
		}else if first.list.Next == nil{
			minPq._swap(0, len(minPq.heap) - 1)
			minPq.heap = minPq.heap[: len(minPq.heap) - 1]
			minPq._sink(0)
		} else{
			new := first.list.Next
			first.next = new.Val
			first.list = new
			minPq._sink(0)
		}

		return val
	}
	return nil
	
}

func (minPq *indexedMinPq) add(list *ListNode) {
	new_elem := listHeap{ list, INF, }
	if list != nil{
		new_elem.next = new_elem.list.Val
	}
	minPq.heap = append(minPq.heap, &new_elem)

	minPq._swim(len(minPq.heap)-1)

}

func (minPq *indexedMinPq) _sink(n int) {
	
	son := -1
	if n*2+2 < len(minPq.heap) && minPq.heap[n*2+2].next < minPq.heap[n*2+1].next{
		son = n*2+2
	} else if n*2+1 < len(minPq.heap){
		son = n*2+1	
	}

	if son != -1 && minPq.heap[n].next > minPq.heap[son].next{
		minPq._swap(n, son)
		minPq._sink(son)
	}
	
}


func (minPq *indexedMinPq) _swim(n int) {
	father := int(math.Ceil(float64(n)/2) - 1)
	if father >= 0 && minPq.heap[n].next < minPq.heap[father].next{
		minPq._swap(n, father)
		minPq._swim(father)
	}
}

func (minPq *indexedMinPq) _swap(a,b int) {
	temp := minPq.heap[a]
	minPq.heap[a] = minPq.heap[b]
	minPq.heap[b] = temp
}
 

// @lc code=end

