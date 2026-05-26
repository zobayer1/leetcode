package main

import "container/list"

// 17. Letter Combinations of a Phone Number

func letterCombinations(digits string) []string {
	keys := [10]string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	q := list.New()
	q.PushBack("")
	for i := 0; i < len(digits); i++ {
		idx := int(digits[i] - '0')
		for len(q.Front().Value.(string)) < i+1 {
			front := q.Front().Value.(string)
			q.Remove(q.Front())
			for j := 0; j < len(keys[idx]); j++ {
				q.PushBack(front + string(keys[idx][j]))
			}
		}
	}
	result := make([]string, q.Len())
	k := 0
	for q.Len() > 0 {
		result[k] = q.Front().Value.(string)
		q.Remove(q.Front())
		k++
	}
	return result
}
