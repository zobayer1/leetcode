package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/* 94. Binary Tree Inorder Traversal */

func traverse(curr *TreeNode, ret *[]int) {
	if curr == nil {
		return
	}
	traverse(curr.Left, ret)
	*ret = append(*ret, curr.Val)
	traverse(curr.Right, ret)
}

func inorderTraversal(root *TreeNode) []int {
	var ret []int
	traverse(root, &ret)
	return ret
}
