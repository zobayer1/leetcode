package main

import "strings"

// 5. Longest Palindromic Substring

func transformString(s string) string {
	var t strings.Builder
	t.Grow(2*len(s) + 3)
	t.WriteByte('^')
	for _, c := range s {
		t.WriteByte('#')
		t.WriteRune(c)
	}
	t.WriteString("#$")
	return t.String()
}

func longestPalindrome(s string) string {
	var t string = transformString(s)
	var n, center, right int = len(t), 0, 0
	var P = make([]int, n)
	for i := 1; i < n-1; i++ {
		mirror := 2*center - i
		if i < right {
			P[i] = min(right-i, P[mirror])
		}
		for t[i+1+P[i]] == t[i-1-P[i]] {
			P[i]++
		}
		if i+P[i] > right {
			center = i
			right = i + P[i]
		}
	}

	var maxlen, center_idx int = 0, 0
	for i := 1; i < n-1; i++ {
		if P[i] > maxlen {
			maxlen = P[i]
			center_idx = i
		}
	}

	start := (center_idx - maxlen) / 2
	return s[start : start+maxlen]
}
