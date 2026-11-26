package main

/* 118. Pascal's Triangle */

func generate(numRows int) [][]int {
	rows := make([][]int, 0, numRows)
	for i := range numRows {
		row := make([]int, i+1)
		row[0], row[i] = 1, 1
		for j := 1; j < i; j++ {
			row[j] = rows[i-1][j-1] + rows[i-1][j]
		}
		rows = append(rows, row)
	}
	return rows
}
