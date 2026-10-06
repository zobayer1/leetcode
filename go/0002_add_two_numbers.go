package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// 2. Add Two Numbers

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var carry, a, b int
	sum := &ListNode{}
	sp := sum
	carry = 0
	for l1 != nil || l2 != nil {
		if l1 != nil {
			a = l1.Val
			l1 = l1.Next
		} else {
			a = 0
		}
		if l2 != nil {
			b = l2.Val
			l2 = l2.Next
		} else {
			b = 0
		}
		sp.Next = &ListNode{Val: (a + b + carry) % 10}
		sp = sp.Next
		carry = (a + b + carry) / 10
	}
	if carry > 0 {
		sp.Next = &ListNode{Val: carry}
	}
	return sum.Next
}
