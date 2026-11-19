package main

/* 88. Merge Sorted Array */

func merge88(nums1 []int, m int, nums2 []int, n int) {
	merged := make([]int, 0, m+n)
	i, j := 0, 0
	for i < m && j < n {
		if nums1[i] < nums2[j] {
			merged = append(merged, nums1[i])
			i += 1
		} else {
			merged = append(merged, nums2[j])
			j += 1
		}
	}
	for i < m {
		merged = append(merged, nums1[i])
		i += 1
	}
	for j < n {
		merged = append(merged, nums2[j])
		j += 1
	}
	copy(nums1, merged)
}
