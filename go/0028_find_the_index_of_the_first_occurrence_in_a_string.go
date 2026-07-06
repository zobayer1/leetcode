package main

import "strings"

// 28. Find the Index of the First Occurrence in a String

func strStr(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}
