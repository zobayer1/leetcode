package main

// 66. Plus One

func plusOne(digits []int) []int {
	carry := 1
	n := len(digits)
	v := make([]int, 0, n+1)
	done := false
	for i := range n {
		if !done {
			s := digits[n-i-1] + carry
			v = append(v, s%10)
			carry = s / 10
			if carry == 0 {
				done = true
			}
		} else {
			v = append(v, digits[n-i-1])
		}
	}
	if carry > 0 {
		v = append(v, carry)
	}
	start, end := 0, len(v)-1
	for start < end {
		v[start], v[end] = v[end], v[start]
		start++
		end--
	}
	return v
}
