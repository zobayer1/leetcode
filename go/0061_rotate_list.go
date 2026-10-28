package main

// 61. Rotate List

func rotateRight(head *ListNode, k int) *ListNode {
	total := 0
	last := head
	for last != nil {
		total++
		if last.Next == nil {
			break
		}
		last = last.Next
	}
	if total == 0 {
		return head
	}
	k = total - k%total
	if k == total {
		return head
	}
	last.Next = head
	curr := head
	for i := 0; i < k-1; i++ {
		curr = curr.Next
	}
	head = curr.Next
	curr.Next = nil
	return head
}
