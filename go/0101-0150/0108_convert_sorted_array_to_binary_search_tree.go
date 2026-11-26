package main

/* 108. Convert Sorted Array to Binary Search Tree */

type Range struct {
	I, J int
	Node *TreeNode
}

func sortedArrayToBST(nums []int) *TreeNode {
	root := &TreeNode{}
	if len(nums) == 1 {
		root.Val = nums[0]
		return root
	}
	stck := []Range{}
	stck = append(stck, Range{I: 0, J: len(nums) - 1, Node: root})
	for len(stck) > 0 {
		top := stck[len(stck)-1]
		stck = stck[:len(stck)-1]
		m := (top.I + top.J) / 2
		top.Node.Val = nums[m]
		if top.I < m {
			top.Node.Left = &TreeNode{}
			stck = append(stck, Range{I: top.I, J: m - 1, Node: top.Node.Left})
		}
		if top.J > m {
			top.Node.Right = &TreeNode{}
			stck = append(stck, Range{I: m + 1, J: top.J, Node: top.Node.Right})
		}
	}
	return root
}
