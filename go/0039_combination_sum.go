package main

import "sort"

// 39. Combination Sum

func combinationSum(candidates []int, target int) [][]int {
	var results [][]int
	var current []int

	sort.Ints(candidates)

	var backtrack func(int, int)
	backtrack = func(start, remain int) {
		if remain == 0 {
			result := make([]int, len(current))
			copy(result, current)
			results = append(results, result)
			return
		}
		for i := start; i < len(candidates); i++ {
			if candidates[i] > remain {
				break
			}
			current = append(current, candidates[i])
			backtrack(i, remain-candidates[i])
			current = current[:len(current)-1]
		}
	}

	backtrack(0, target)
	return results
}
