package main

// 67. Add Binary

func addBinary(a string, b string) string {
	na, nb := len(a), len(b)
	n := max(na, nb)
	v := make([]byte, 0, n+1)
	c := 0
	for i := range n {
		ai, bi := 0, 0
		if i < na {
			ai = int(a[na-1-i] - '0')
		}
		if i < nb {
			bi = int(b[nb-1-i] - '0')
		}
		s := (ai + bi + c)
		v = append(v, byte((s&1)+'0'))
		c = s >> 1
	}
	if c > 0 {
		v = append(v, byte(c+'0'))
	}
	start, end := 0, len(v)-1
	for start < end {
		v[start], v[end] = v[end], v[start]
		start++
		end--
	}
	return string(v)
}
