package main

// 70. Climbing Stairs

func climbStairs(n int) int {
	a, b, c := 0, 1, 1
	for i := 0; i < n; i++ {
		c = a + b
		a, b = b, c
	}
	return c
}
