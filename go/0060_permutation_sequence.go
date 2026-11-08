package main

import "slices"

// 60. Permutation Sequence

func getPermutation(n int, k int) string {
	factorials := [10]int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
	digits := make([]byte, n)
	for i := range n {
		digits[i] = byte(i + '1')
	}
	k--
	fact := factorials[n]
	var idx int
	result := make([]byte, 0, n)
	for i := n; i > 0; i-- {
		fact = int(fact / i)
		idx = k / fact
		k = k % fact
		result = append(result, digits[idx])
		digits = slices.Delete(digits, idx, idx+1)
	}
	return string(result)
}
