package main

// 22. Generate Parentheses

func recur(a, b, s int, curr []rune, paths *[]string) {
	if a == 0 && b == 0 {
		*paths = append(*paths, string(curr))
		return
	}
	if a != 0 {
		curr = append(curr, '(')
		recur(a-1, b, s+1, curr, paths)
		curr = curr[:len(curr)-1]
	}
	if b != 0 && s > 0 {
		curr = append(curr, ')')
		recur(a, b-1, s-1, curr, paths)
		curr = curr[:len(curr)-1]
	}
}

func generateParenthesis(n int) []string {
	paths := []string{}
	curr := []rune{}
	recur(n, n, 0, curr, &paths)
	return paths
}
