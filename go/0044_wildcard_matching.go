package main

// 44. Wildcard Matching

func isMatch2(s string, p string) bool {
	n, m := len(s), len(p)
	dp := [2][2001]bool{}
	for i := n; i >= 0; i-- {
		dp[i&1][m] = i == n
		for j := m - 1; j >= 0; j-- {
			if p[j] == '*' {
				dp[i&1][j] = dp[i&1][j+1] || (i < n && dp[(i+1)&1][j])
			} else if i < n && (p[j] == '?' || s[i] == p[j]) {
				dp[i&1][j] = dp[(i+1)&1][j+1]
			} else {
				dp[i&1][j] = false
			}
		}
	}
	return dp[0][0]
}
