package main

import "sort"

// 40. Combination Sum II

func combinationSum2(candidates []int, target int) [][]int {
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
			if i > start && candidates[i] == candidates[i-1] {
				continue
			}
			current = append(current, candidates[i])
			backtrack(i+1, remain-candidates[i])
			current = current[:len(current)-1]
		}
	}

	backtrack(0, target)
	return results
}
