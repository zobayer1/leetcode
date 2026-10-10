package main

// 24. Swap Nodes in Pairs

func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{Next: head}
	prev := dummy

	for prev.Next != nil && prev.Next.Next != nil {
		first := prev.Next
		second := first.Next

		prev.Next, first.Next, second.Next = second, second.Next, first

		prev = first
	}
	return dummy.Next
}
