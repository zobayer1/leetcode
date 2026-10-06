package main

import "math"

// 8. String to Integer

func myAtoi(s string) int {
	start := 0
	n := len(s)
	for start < n && s[start] == ' ' {
		start++
	}
	if start == n {
		return 0
	}
	isNeg := false
	if s[start] == '-' {
		isNeg = true
		start++
	} else if s[start] == '+' {
		start++
	}
	var num int64 = 0
	for ; start < n; start++ {
		if s[start] < '0' || s[start] > '9' {
			break
		}
		num = num*10 + int64(s[start]-'0')
		if isNeg {
			if -num <= math.MinInt32 {
				return math.MinInt32
			}
		} else {
			if num >= math.MaxInt32 {
				return math.MaxInt32
			}
		}
	}
	if isNeg {
		num = -num
	}
	return int(num)
}
