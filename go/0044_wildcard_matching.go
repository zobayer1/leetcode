package main

// 44. Wildcard Matching
// Rename signature: func isMatch(string, string) bool

func isMatch2(s string, p string) bool {
	n, m := len(s), len(p)
	s_idx, p_idx := 0, 0
	star_idx, skip_idx := -1, -1
	for s_idx < n {
		if p_idx < m && (p[p_idx] == '?' || s[s_idx] == p[p_idx]) {
			s_idx++
			p_idx++
		} else if p_idx < m && p[p_idx] == '*' {
			star_idx = p_idx
			skip_idx = s_idx
			p_idx++
		} else if star_idx != -1 {
			p_idx = star_idx + 1
			skip_idx++
			s_idx = skip_idx
		} else {
			return false
		}
	}
	for p_idx < m && p[p_idx] == '*' {
		p_idx++
	}
	return p_idx == m
}
