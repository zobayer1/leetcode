package main

import "math"

// 29. Divide Two Integers

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func divide(dividend int, divisor int) int {
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}

	isNegative := (dividend < 0) != (divisor < 0)

	dividend = abs(dividend)
	divisor = abs(divisor)

	quotient := 0

	for dividend >= divisor {
		shift := 0
		for dividend >= (divisor << (shift + 1)) {
			shift++
		}
		dividend -= (divisor << shift)
		quotient += (1 << shift)
	}

	if isNegative {
		return -quotient
	}
	return quotient
}
