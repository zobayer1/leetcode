package main

/* 119. Pascal's Triangle II */

func getRow(rowIndex int) []int {
	row := make([]int, rowIndex+1)
	row[0] = 1
	for k := 1; k <= rowIndex; k++ {
		row[k] = row[k-1] * (rowIndex - k + 1) / k
	}
	return row
}
