package main

// 45. Jump Game II

func jump(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}
	jumps := 0
	last := 0
	furthest := 0
	for i := 0; i < n-1; i++ {
		furthest = max(furthest, i+nums[i])
		if i == last {
			last = furthest
			jumps++
			if last >= n-1 {
				break
			}
		}
	}
	return jumps
}
