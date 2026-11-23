package main

import "slices"

/* 100. Same Tree */

func preOrder(curr *TreeNode, vals *[]int) {
	if curr == nil {
		*vals = append(*vals, -1000000)
		return
	}
	*vals = append(*vals, curr.Val)
	preOrder(curr.Left, vals)
	preOrder(curr.Right, vals)
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	var pNodes, qNodes []int
	preOrder(p, &pNodes)
	preOrder(q, &qNodes)
	return slices.Equal(pNodes, qNodes)
}
