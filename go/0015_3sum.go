package main

import "slices"

// 15. 3Sum

func threeSum(nums []int) [][]int {
	n := len(nums)
	var triplets []int
	slices.Sort(nums[:])
	if n > 0 && nums[n-1] < 0 {
		return [][]int{}
	}
	for i := 0; i <= n-3 && nums[i] <= 0; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j, k := i+1, n-1; j < k; {
			sum := nums[i] + nums[j] + nums[k]
			left, right := nums[j], nums[k]
			if sum == 0 {
				triplets = append(triplets, nums[i], nums[j], nums[k])
				for j < k && nums[j] == left {
					j++
				}
				for j < k && nums[k] == right {
					k--
				}
			} else if sum > 0 {
				for j < k && nums[k] == right {
					k--
				}
			} else {
				for j < k && nums[j] == left {
					j++
				}
			}
		}
	}
	p := len(triplets) / 3
	result := make([][]int, 0, p)
	for i := 0; i < len(triplets); i += 3 {
		result = append(result, triplets[i:i+3])
	}
	return result
}
