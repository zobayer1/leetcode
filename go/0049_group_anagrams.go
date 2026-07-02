package main

import "sort"

// 49. Group Anagrams

func groupAnagrams(strs []string) [][]string {
	anagrams := map[string][]string{}
	for _, s := range strs {
		t := []rune(s)
		sort.Slice(t, func(i, j int) bool {
			return t[i] < t[j]
		})
		p := string(t)
		anagrams[p] = append(anagrams[p], s)
	}
	result := make([][]string, 0, len(anagrams))
	for _, group := range anagrams {
		result = append(result, group)
	}
	return result
}
