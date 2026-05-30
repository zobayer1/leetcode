package main

import (
	"strconv"
	"strings"
)

// 38. Count and Say

func rle(s *string) string {
	var sb strings.Builder
	cnt := 0
	last := rune(0)
	for _, ch := range *s {
		if ch != last {
			if cnt > 0 {
				sb.WriteString(strconv.Itoa(cnt))
				sb.WriteRune(last)
			}
			last = ch
			cnt = 0
		}
		cnt++
	}
	if cnt > 0 {
		sb.WriteString(strconv.Itoa(cnt))
		sb.WriteRune(last)
	}
	return sb.String()
}

func countAndSay(n int) string {
	s := "1"
	for i := 2; i <= n; i++ {
		s = rle(&s)
	}
	return s
}
