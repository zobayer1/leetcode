package main

/* 136. Single Number */

func singleNumber(nums []int) int {
	n := 0
	for _, i := range nums {
		n ^= i
	}
	return n
}
