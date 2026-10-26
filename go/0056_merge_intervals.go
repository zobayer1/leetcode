package main

import "sort"

// 56. Merge Intervals

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return (intervals[i][0] < intervals[j][0]) || (intervals[i][0] == intervals[j][0] && intervals[i][1] < intervals[j][1])
	})
	res := make([][]int, 0, len(intervals))
	res = append(res, intervals[0])
	k := 0
	for i := 1; i < len(intervals); i++ {
		if res[k][1] < intervals[i][0] {
			k++
			res = append(res, intervals[i])
		} else {
			res[k][1] = max(res[k][1], intervals[i][1])
		}
	}
	return res
}
