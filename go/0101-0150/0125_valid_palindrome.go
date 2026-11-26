package main

/* 125. Valid Palindrome */

func convAlphaNum(c byte) (byte, bool) {
	if c >= 'a' && c <= 'z' {
		return c, true
	}
	if c >= 'A' && c <= 'Z' {
		return byte(c + 32), true
	}
	return c, c >= '0' && c <= '9'
}

func isPalindrome(s string) bool {
	i, j := 0, len(s)-1
	for i < j {
		ci, vi := convAlphaNum(s[i])
		if !vi {
			i++
			continue
		}
		cj, vj := convAlphaNum(s[j])
		if !vj {
			j--
			continue
		}
		if ci != cj {
			break
		}
		i++
		j--
	}
	return i >= j
}
