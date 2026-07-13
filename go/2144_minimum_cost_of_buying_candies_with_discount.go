package main

import "slices"

// 2144. Minimum Cost of Buying Candies With Discount

func minimumCost(cost []int) int {
	slices.Sort(cost[:])
	ret := 0
	for i := len(cost); i > 0; i-- {
		ret += cost[i-1]
		i--
		if i > 0 {
			ret += cost[i-1]
			i--
		}
	}
	return ret
}
