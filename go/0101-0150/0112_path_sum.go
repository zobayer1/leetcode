package main

/* 112. Path Sum */

func traverse(root *TreeNode, targetSum int) bool {
	if root == nil {
		return targetSum == 0
	}
	targetSum -= root.Val
	if root.Left == nil && root.Right == nil {
		return targetSum == 0
	}
	return (root.Left != nil && traverse(root.Left, targetSum)) || (root.Right != nil && traverse(root.Right, targetSum))
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	return traverse(root, targetSum)
}
