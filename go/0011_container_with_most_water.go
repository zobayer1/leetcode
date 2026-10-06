package main

// 11. Container with Most Water

func maxArea(height []int) int {
	n := len(height)
	mx := 0
	for i, j := 0, n-1; i < j; {
		mx = max(mx, (j-i)*min(height[i], height[j]))
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return mx
}
