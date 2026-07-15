package main

// 20. Valid Parentheses

func oppose(p1, p2 rune) bool {
	switch {
	case p1 == '(' && p2 == ')', p1 == ')' && p2 == '(':
		return true
	case p1 == '{' && p2 == '}', p1 == '}' && p2 == '{':
		return true
	case p1 == '[' && p2 == ']', p1 == ']' && p2 == '[':
		return true
	default:
		return false
	}
}

func isValid(s string) bool {
	st := []rune{}
	for _, ch := range s {
		if ch == '(' || ch == '{' || ch == '[' {
			st = append(st, ch)
			continue
		}
		if len(st) == 0 {
			return false
		}
		last := len(st) - 1
		t := st[last]
		st[last] = 0
		st = st[:last]
		if !oppose(t, ch) {
			return false
		}
	}
	return len(st) == 0
}
