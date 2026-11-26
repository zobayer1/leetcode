package main

import "slices"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/* 101. Symmetric Tree */

func preord_normal(root *TreeNode, vals *[]int) {
	if root == nil {
		*vals = append(*vals, -1)
		return
	}
	*vals = append(*vals, root.Val)
	preord_normal(root.Left, vals)
	preord_normal(root.Right, vals)
}

func preord_mirror(root *TreeNode, vals *[]int) {
	if root == nil {
		*vals = append(*vals, -1)
		return
	}
	*vals = append(*vals, root.Val)
	preord_mirror(root.Right, vals)
	preord_mirror(root.Left, vals)
}

func isSymmetric(root *TreeNode) bool {
	var lvals, rvals []int
	preord_normal(root, &lvals)
	preord_mirror(root, &rvals)
	return slices.Equal(lvals, rvals)
}
