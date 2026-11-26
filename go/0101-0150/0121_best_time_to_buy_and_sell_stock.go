package main

/* 121. Best Time to Buy and Sell Stock */

func maxProfit(prices []int) int {
	n := len(prices)
	if n == 1 {
		return 0
	}
	profit, cost := 0, prices[0]
	for i := 1; i < n; i++ {
		profit = max(profit, prices[i]-cost)
		cost = min(cost, prices[i])
	}
	return profit
}
