package main

// 42. Trapping Rain Water

func trap(height []int) int {
	maxleft, maxright := 0, 0
	left, right := 0, len(height)-1
	total := 0
	for left < right {
		if height[left] <= height[right] {
			maxleft = max(maxleft, height[left])
			total += maxleft - height[left]
			left++
		} else {
			maxright = max(maxright, height[right])
			total += maxright - height[right]
			right--
		}
	}
	return total
}
