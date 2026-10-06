package main

// 14. Longest Common Prefix

func longestCommonPrefix(strs []string) string {
	j := 0
	done := false
	for ; j < len(strs[0]); j++ {
		c := strs[0][j]
		for i := 1; i < len(strs); i++ {
			if j >= len(strs[i]) || strs[i][j] != c {
				done = true
				break
			}
		}
		if done {
			break
		}
	}
	return strs[0][0:j]
}
