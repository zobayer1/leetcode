package main

import "sort"

// 46. Permutations

func reverseRange(nums []int, start, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

func nextPermutation2(nums []int) bool {
	n := len(nums)
	if n <= 1 {
		return false
	}
	i := n - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		reverseRange(nums, 0, n-1)
		return false
	}
	j := n - 1
	for nums[j] <= nums[i] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	reverseRange(nums, i+1, n-1)
	return true
}

func permute(nums []int) [][]int {
	f := 1
	for i := 2; i <= len(nums); i++ {
		f *= i
	}
	perms := make([][]int, f)
	sort.Ints(nums)
	for true {
		seq := make([]int, len(nums))
		copy(seq, nums)
		perms = append(perms, seq)
		next := nextPermutation2(nums)
		if !next {
			break
		}
	}
	return perms
}
