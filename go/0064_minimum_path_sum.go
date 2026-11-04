package main

// 64. Minimum Path Sum

func minPathSum(grid [][]int) int {
	r, c := len(grid), len(grid[0])
	for i := r - 2; i >= 0; i-- {
		grid[i][c-1] += grid[i+1][c-1]
	}
	for i := c - 2; i >= 0; i-- {
		grid[r-1][i] += grid[r-1][i+1]
	}
	for i := r - 2; i >= 0; i-- {
		for j := c - 2; j >= 0; j-- {
			grid[i][j] += min(grid[i+1][j], grid[i][j+1])
		}
	}
	return grid[0][0]
}
