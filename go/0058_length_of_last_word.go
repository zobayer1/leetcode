package main

// 58. Length of Last Word

func lengthOfLastWord(s string) int {
	n := len(s)
	var i int
	for i = range n {
		if s[n-i-1] != ' ' {
			break
		}
	}
	n = n - i
	res := 0
	for i = range n {
		if s[n-i-1] == ' ' {
			break
		}
		res++
	}
	return res
}
