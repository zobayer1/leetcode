package main

// 31. Next Permutation

func nextPermutation(nums []int) {
	if len(nums) <= 1 {
		return
	}

	i := len(nums) - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}

	if i >= 0 {
		j := len(nums) - 1
		for nums[j] <= nums[i] {
			j--
		}
		nums[i], nums[j] = nums[j], nums[i]
	}

	left := i + 1
	right := len(nums) - 1

	for left < right {
		nums[left], nums[right] = nums[right], nums[left]
		left++
		right--
	}
}
