package main

// 57. Insert Interval

func insert(intervals [][]int, newInterval []int) [][]int {
	n := len(intervals)
	lo, hi := newInterval[0], newInterval[1]
	var lt, rt int
	for lt = 0; lt < n; lt++ {
		if intervals[lt][1] >= lo {
			break
		}
	}
	for rt = n - 1; rt >= 0; rt-- {
		if intervals[rt][0] <= hi {
			break
		}
	}
	res := make([][]int, 0, n+1)
	if lt > 0 {
		res = append(res, intervals[:lt]...)
	}
	if 0 <= lt && lt < n {
		lo = min(lo, intervals[lt][0])
	}
	if 0 <= rt && rt < n {
		hi = max(hi, intervals[rt][1])
	}
	res = append(res, []int{lo, hi})
	if rt+1 < n {
		res = append(res, intervals[rt+1:n]...)
	}
	return res
}
