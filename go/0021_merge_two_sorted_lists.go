package main

// 21. Merge Two Sorted Lists

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	head := &ListNode{}
	curr := head
	for list1 != nil || list2 != nil {
		var val int
		if list1 == nil {
			val = list2.Val
			list2 = list2.Next
		} else if list2 == nil {
			val = list1.Val
			list1 = list1.Next
		} else {
			if list1.Val < list2.Val {
				val = list1.Val
				list1 = list1.Next
			} else {
				val = list2.Val
				list2 = list2.Next
			}
		}
		curr.Next = &ListNode{Val: val}
		curr = curr.Next
	}
	return head.Next
}
