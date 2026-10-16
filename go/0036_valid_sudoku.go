package main

// 36. Valid Sudoku

func isValidSudoku(board [][]byte) bool {
	rcnt := [9][10]int{}
	lcnt := [9][10]int{}
	scnt := [9][10]int{}
	for i := range 9 {
		for j := range 9 {
			if board[i][j] == '.' {
				continue
			}
			val := int(board[i][j] - '0')
			if rcnt[i][val] > 0 {
				return false
			}
			rcnt[i][val]++
			if lcnt[j][val] > 0 {
				return false
			}
			lcnt[j][val]++
			s := (i/3)*3 + (j / 3)
			if scnt[s][val] > 0 {
				return false
			}
			scnt[s][val]++
		}
	}
	return true
}
