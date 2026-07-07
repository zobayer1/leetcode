package main

// 301. Remove Invalid Parentheses

type solution struct {
	dp    [27][27]int
	paths [27][27]map[string]struct{}
}

func (sol *solution) merge(ans map[string]struct{}, prefix string, suffixes map[string]struct{}) {
	for suffix := range suffixes {
		ans[prefix+suffix] = struct{}{}
	}
}

func (sol *solution) walk(i, b int, s string) map[string]struct{} {
	if i == len(s) {
		if b == 0 {
			return map[string]struct{}{"": {}}
		}
		return nil
	}

	if sol.paths[i][b] != nil {
		return sol.paths[i][b]
	}

	ans := make(map[string]struct{})

	switch s[i] {
	case '(':
		if sol.dp[i][b] == 1+sol.dp[i+1][b] {
			sol.merge(ans, "", sol.walk(i+1, b, s))
		}
		if sol.dp[i][b] == sol.dp[i+1][b+1] {
			sol.merge(ans, "(", sol.walk(i+1, b+1, s))
		}
	case ')':
		if sol.dp[i][b] == 1+sol.dp[i+1][b] {
			sol.merge(ans, "", sol.walk(i+1, b, s))
		}
		if b > 0 && sol.dp[i][b] == sol.dp[i+1][b-1] {
			sol.merge(ans, ")", sol.walk(i+1, b-1, s))
		}
	default:
		sol.merge(ans, string(s[i]), sol.walk(i+1, b, s))
	}

	sol.paths[i][b] = ans
	return ans
}

func (sol *solution) solve(s string) {
	n := len(s)
	for i := 1; i < 26; i++ {
		sol.dp[n][i] = 1 << 20
	}
	for i := n - 1; i >= 0; i-- {
		for b := 0; b <= n; b++ {
			if s[i] != '(' && s[i] != ')' {
				sol.dp[i][b] = sol.dp[i+1][b]
			} else if s[i] == '(' {
				sol.dp[i][b] = min(1+sol.dp[i+1][b], sol.dp[i+1][b+1])
			} else {
				sol.dp[i][b] = 1 + sol.dp[i+1][b]
				if b > 0 {
					sol.dp[i][b] = min(sol.dp[i][b], sol.dp[i+1][b-1])
				}
			}
		}
	}
}

func removeInvalidParentheses(s string) []string {
	var sl solution
	sl.solve(s)
	paths := sl.walk(0, 0, s)

	result := make([]string, 0, len(paths))
	for key := range paths {
		result = append(result, key)
	}
	return result
}
