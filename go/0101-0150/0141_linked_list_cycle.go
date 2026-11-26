package main

type ListNode struct {
	Val  int
	Next *ListNode
}

/* 141. Linked List Cycle */

func hasCycle(head *ListNode) bool {
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			return true
		}
	}
	return false
}
