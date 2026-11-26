package main

/* 111. Minimum Depth of Binary Tree */

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	ldepth, rdepth := 0, 0
	if root.Left != nil {
		ldepth = minDepth(root.Left)
	}
	if root.Right != nil {
		rdepth = minDepth(root.Right)
	}
	if ldepth == 0 {
		return rdepth + 1
	}
	if rdepth == 0 {
		return ldepth + 1
	}
	return 1 + min(ldepth, rdepth)
}
