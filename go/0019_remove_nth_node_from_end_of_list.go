package main

// 19. Remove Nth Node From End of List

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	ptr_r, ptr_l := head, (*ListNode)(nil)
	for i := 0; ptr_r != nil; i++ {
		ptr_r = ptr_r.Next
		if i == n {
			ptr_l = head
		} else if i > n {
			ptr_l = ptr_l.Next
		}
	}
	if ptr_l == nil {
		head = head.Next
	} else if ptr_l.Next != nil {
		ptr_l.Next = ptr_l.Next.Next
	}
	return head
}
