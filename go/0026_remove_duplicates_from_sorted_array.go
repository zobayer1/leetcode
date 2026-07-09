package main

// 26. Remove Duplicates from Sorted Array

func removeDuplicates(nums []int) int {
	k := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			continue
		}
		nums[k] = nums[i]
		k++
	}
	nums = nums[:k]
	return k
}
