package main

import "strings"

// 65. Valid Number

func isValidChars(s string) bool {
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c != 'E' && c != 'e' && (c < '0' || c > '9') && c != '+' && c != '-' && c != '.' {
			return false
		}
	}
	return true
}

func findExPos(s string) int {
	first := strings.IndexAny(s, "eE")
	if first == -1 {
		return len(s)
	}
	if strings.ContainsAny(s[first+1:], "eE") {
		return -1
	}
	return first
}

func findDotPos(s string) int {
	first := strings.IndexByte(s, '.')
	if first == -1 {
		return len(s)
	}
	if strings.IndexByte(s[first+1:], '.') != -1 {
		return -1
	}
	return first
}

func isInteger(s string) bool {
	if len(s) == 0 {
		return false
	}
	for i := 0; i < len(s); i++ {
		if s[i] < '0' || s[i] > '9' {
			return false
		}
	}
	return true
}

func isNumber(s string) bool {
	if !isValidChars(s) {
		return false
	}

	exPos := findExPos(s)
	if exPos == -1 {
		return false
	}

	if exPos < len(s) {
		exponent := s[exPos+1:]
		if len(exponent) == 0 {
			return false
		}
		if exponent[0] == '+' || exponent[0] == '-' {
			exponent = exponent[1:]
		}
		if !isInteger(exponent) {
			return false
		}
	}

	number := s[:exPos]
	if len(number) == 0 {
		return false
	}
	if number[0] == '+' || number[0] == '-' {
		number = number[1:]
	}
	if len(number) == 0 {
		return false
	}

	dotPos := findDotPos(number)
	if dotPos == -1 {
		return false
	}
	if dotPos == len(number) {
		return isInteger(number)
	}

	before := number[:dotPos]
	after := number[dotPos+1:]

	if len(before) == 0 && len(after) == 0 {
		return false
	}
	if len(before) > 0 && !isInteger(before) {
		return false
	}
	if len(after) > 0 && !isInteger(after) {
		return false
	}

	return true
}
