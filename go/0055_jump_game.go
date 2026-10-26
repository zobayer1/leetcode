package main

// 55. Jump Game

func canJump(nums []int) bool {
	n := len(nums)
	jump := 0
	for i := range n - 1 {
		jump = max(jump, i+nums[i])
		if jump <= i {
			return false
		}
		if jump >= n-1 {
			return true
		}
	}
	return jump >= n-1
}
