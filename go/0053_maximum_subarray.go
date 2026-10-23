package main

// 53. Maximum Subarray

func maxSubArray(nums []int) int {
	currentSum, globalMax := 0, nums[0]
	for i := range nums {
		currentSum = max(nums[i], currentSum+nums[i])
		globalMax = max(globalMax, currentSum)
	}
	return globalMax
}
