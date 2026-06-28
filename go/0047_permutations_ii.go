package main

import "sort"

// 47. Permutations II

func reverseRangeU(nums []int, start, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

func nextPermutationU(nums []int) bool {
	n := len(nums)
	if n <= 1 {
		return false
	}
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		reverseRangeU(nums, 0, n-1)
		return false
	}
	j := n - 1
	for nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	reverseRangeU(nums, i+1, n-1)
	return true
}

func permuteUnique(nums []int) [][]int {
	var perms [][]int
	sort.Ints(nums)
	for true {
		seq := make([]int, len(nums))
		copy(seq, nums)
		perms = append(perms, seq)
		next := nextPermutationU(nums)
		if !next {
			break
		}
	}
	return perms
}
