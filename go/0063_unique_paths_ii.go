package main

// 63. Unique Paths II

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	if obstacleGrid[m-1][n-1] == 1 {
		return 0
	}
	for i := range m {
		for j := range n {
			obstacleGrid[i][j] ^= 1
		}
	}
	for i := m - 2; i >= 0; i-- {
		if obstacleGrid[i][n-1] == 0 {
			for i = i - 1; i >= 0; i-- {
				obstacleGrid[i][n-1] = 0
			}
		}
	}
	for i := n - 2; i >= 0; i-- {
		if obstacleGrid[m-1][i] == 0 {
			for i = i - 1; i >= 0; i-- {
				obstacleGrid[m-1][i] = 0
			}
		}
	}
	for i := m - 2; i >= 0; i-- {
		for j := n - 2; j >= 0; j-- {
			if obstacleGrid[i][j] == 0 {
				continue
			}
			obstacleGrid[i][j] = obstacleGrid[i+1][j] + obstacleGrid[i][j+1]
		}
	}
	return obstacleGrid[0][0]
}
