package main

// 35. Search Insert Position

func searchInsert(nums []int, target int) int {
	low, high := 0, len(nums)-1
	pos := -1
	for low <= high {
		mid := (low + high) / 2
		if target <= nums[mid] {
			pos = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	if pos == -1 {
		pos = len(nums)
	}
	return pos
}
