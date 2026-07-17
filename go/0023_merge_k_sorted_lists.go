package main

import "container/heap"

// 23. Merge k Sorted Lists

type PriorityQueue []*ListNode

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Val < pq[j].Val
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*ListNode)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func mergeKLists(lists []*ListNode) *ListNode {
	pq := &PriorityQueue{}
	heap.Init(pq)
	for _, node := range lists {
		if node != nil {
			heap.Push(pq, node)
		}
	}

	head := &ListNode{}
	curr := head

	for pq.Len() > 0 {
		top := heap.Pop(pq).(*ListNode)
		curr.Next = top
		curr = curr.Next
		if top.Next != nil {
			heap.Push(pq, top.Next)
		}
	}

	return head.Next
}
