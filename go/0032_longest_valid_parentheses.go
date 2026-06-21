package main

// 32. Longest Valid Parentheses

func longestValidParentheses(s string) int {
	left, right := 0, 0
	n := len(s)
	mx := 0
	for i := range n {
		if s[i] == '(' {
			left++
		} else if s[i] == ')' {
			right++
		}
		if left == right {
			mx = max(mx, 2*right)
		}
		if right > left {
			left, right = 0, 0
		}
	}
	left, right = 0, 0
	for i := n - 1; i >= 0; i-- {
		if s[i] == '(' {
			left++
		} else if s[i] == ')' {
			right++
		}
		if left == right {
			mx = max(mx, 2*right)
		}
		if left > right {
			left, right = 0, 0
		}
	}
	return mx
}
