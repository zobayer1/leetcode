package main

// 69. Sqrt(x)

func mySqrt(x int) int {
	if x < 2 {
		return x
	}
	lo, hi := 1, x
	for lo <= hi {
		m := lo + (hi-lo)/2
		if x/m == m {
			return m
		}
		if m < x/m {
			lo = m + 1
		} else {
			hi = m - 1
		}
	}
	return hi
}
