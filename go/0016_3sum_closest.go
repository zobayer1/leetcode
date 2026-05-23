package main

import "slices"

// 16. 3Sum Closest

func absInt(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func threeSumClosest(nums []int, target int) int {
	slices.Sort(nums[:])
	closest := nums[0] + nums[1] + nums[2]
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j, k := i+1, len(nums)-1; j < k; {
			sum := nums[i] + nums[j] + nums[k]
			if sum == target {
				return sum
			}
			if absInt(sum-target) < absInt(closest-target) {
				closest = sum
			}
			left, right := nums[j], nums[k]
			if sum < target {
				for j < k && nums[j] == left {
					j++
				}
			} else {
				for j < k && nums[k] == right {
					k--
				}
			}
		}
	}
	return closest
}
