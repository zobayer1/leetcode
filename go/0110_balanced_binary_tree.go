package main

/* 110. Balanced Binary Tree */

func depth(curr *TreeNode) (int, bool) {
	if curr == nil {
		return 0, true
	}
	lDepth, isLBalanced := depth(curr.Left)
	if !isLBalanced {
		return 0, false
	}
	rDepth, isRBalanced := depth(curr.Right)
	if !isRBalanced {
		return 0, false
	}
	return 1 + max(lDepth, rDepth), absInt(lDepth-rDepth) <= 1
}

func isBalanced(root *TreeNode) bool {
	_, balanced := depth(root)
	return balanced
}
