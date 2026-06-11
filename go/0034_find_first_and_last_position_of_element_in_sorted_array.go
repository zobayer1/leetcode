package main

// 34. Find First and Last Position of Element in Sorted Array

func searchRange(nums []int, target int) []int {
	low, high := 0, len(nums)-1
	start_idx, end_idx := -1, -1

	for low <= high {
		mid := (low + high) / 2
		if nums[mid] == target {
			l_low, l_high := low, mid
			for l_low <= l_high {
				l_mid := (l_low + l_high) / 2
				if nums[l_mid] < target {
					l_low = l_mid + 1
				} else {
					start_idx = l_mid
					l_high = l_mid - 1
				}
			}
			r_low, r_high := mid, high
			for r_low <= r_high {
				r_mid := (r_low + r_high) / 2
				if nums[r_mid] > target {
					r_high = r_mid - 1
				} else {
					end_idx = r_mid
					r_low = r_mid + 1
				}
			}
			return []int{start_idx, end_idx}
		}
		if target < nums[mid] {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return []int{start_idx, end_idx}
}
