package main

// 3120. Count the Number of Special Characters I

func numberOfSpecialChars(word string) int {
	up := make([]int, 26)
	lo := make([]int, 26)
	for _, ch := range word {
		if ch >= 'A' && ch <= 'Z' {
			up[ch-'A'] = 1
		} else if ch >= 'a' && ch <= 'z' {
			lo[ch-'a'] = 1
		}
	}
	ret := 0
	for i := 0; i < 26; i++ {
		if (up[i] & lo[i]) > 0 {
			ret++
		}
	}
	return ret
}
