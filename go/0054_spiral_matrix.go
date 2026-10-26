package main

// 54. Spiral Matrix

func spiralOrder(matrix [][]int) []int {
	minr, minc := 0, 0
	maxr, maxc := len(matrix), len(matrix[0])
	total := maxr * maxc
	res := make([]int, total)
	delr, delc := 0, 1
	r, c := 0, 0
	for k := range total {
		res[k] = matrix[r][c]
		r += delr
		c += delc
		if c == maxc {
			minr++
			r -= delr
			c -= delc
			delr, delc = 1, 0
			r += delr
			c += delc
		} else if r == maxr {
			maxc--
			r -= delr
			c -= delc
			delr, delc = 0, -1
			r += delr
			c += delc
		} else if c < minc {
			maxr--
			r -= delr
			c -= delc
			delr, delc = -1, 0
			r += delr
			c += delc
		} else if r < minr {
			minc++
			r -= delr
			c -= delc
			delr, delc = 0, 1
			r += delr
			c += delc
		}
	}
	return res
}
