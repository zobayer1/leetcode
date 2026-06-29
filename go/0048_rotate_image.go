package main

import "slices"

// 48. Rotate Image

func rotate(matrix [][]int) {
	n := len(matrix)
	for i := range n - 1 {
		for j := i + 1; j < n; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
	for i := range n {
		slices.Reverse(matrix[i])
	}
}
