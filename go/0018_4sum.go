package main

import "slices"

// 18. 4Sum

func fourSum(nums []int, target int) [][]int {
	n := len(nums)
	if n < 4 {
		return [][]int{}
	}
	slices.Sort(nums[:])
	var quads []int
	for i := 0; i < n-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < n-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			left, right := j+1, n-1
			for left < right {
				sum := nums[i] + nums[j] + nums[left] + nums[right]
				ll, rr := nums[left], nums[right]
				if sum == target {
					quads = append(quads, nums[i], nums[j], nums[left], nums[right])
					for left < right && nums[left] == ll {
						left++
					}
					for left < right && nums[right] == rr {
						right--
					}
				} else if sum > target {
					for left < right && nums[right] == rr {
						right--
					}
				} else {
					for left < right && nums[left] == ll {
						left++
					}
				}
			}
		}
	}
	p := len(quads) / 4
	result := make([][]int, 0, p)
	for i := 0; i < len(quads); i += 4 {
		result = append(result, quads[i:i+4])
	}
	return result
}
