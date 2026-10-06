package main

// Roman to Integer

func romanToInt(s string) int {
	var romanVal [128]int
	romanVal['I'] = 1
	romanVal['V'] = 5
	romanVal['X'] = 10
	romanVal['L'] = 50
	romanVal['C'] = 100
	romanVal['D'] = 500
	romanVal['M'] = 1000

	val := 0
	n := len(s)

	for i := 0; i < n; i++ {
		curr := romanVal[s[i]]
		if i+1 < n && curr < romanVal[s[i+1]] {
			val -= curr
		} else {
			val += curr
		}
	}
	return val
}
