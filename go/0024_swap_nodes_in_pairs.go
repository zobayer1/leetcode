package main

// 24. Swap Nodes in Pairs

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	first := head
	second := head.Next
	first.Next = second.Next
	second.Next = first
	head = second
	ptemp := head.Next
	temp := head.Next.Next
	for temp != nil && temp.Next != nil {
		first = temp
		second = temp.Next
		first.Next = second.Next
		second.Next = first
		ptemp.Next = second
		ptemp = second.Next
		temp = second.Next.Next
	}
	return head
}
