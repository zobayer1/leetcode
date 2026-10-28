package main

// 59. Spiral Matrix II

func generateMatrix(n int) [][]int {
	minr, minc := 0, 0
	maxr, maxc := n, n
	total := n * n
	res := make([][]int, n)
	for i := range res {
		res[i] = make([]int, n)
	}
	delr, delc := 0, 1
	r, c := 0, 0
	for k := range total {
		res[r][c] = k + 1
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
