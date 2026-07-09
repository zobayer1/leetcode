package main

func reverseKGroup(head *ListNode, k int) *ListNode {
	if k == 1 {
		return head
	}
	dummy := &ListNode{Next: head}
	prev, curr := dummy, head
	stack := make([]*ListNode, 0, k)
	for curr != nil {
		stack = append(stack, curr)
		next := curr.Next
		if len(stack) == k {
			for len(stack) > 0 {
				top := stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				prev.Next = top
				prev = prev.Next
			}
			prev.Next = next
		}
		curr = next
	}
	return dummy.Next
}
