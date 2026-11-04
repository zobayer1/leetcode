package main

// 62. Unique Paths

func gcd(a, b int) int {
	for b > 0 {
		b, a = a%b, b
	}
	return a
}

func uniquePaths(m int, n int) int {
	if m == 1 || n == 1 {
		return 1
	}
	total := m + n - 2
	k := min(m, n) - 1
	res := 1
	for i := 1; i <= k; i++ {
		num := total - k + i
		deno := i

		g := gcd(res, deno)
		res /= g
		deno /= g

		g = gcd(num, deno)
		num /= g
		deno /= g

		res *= num
	}
	return res
}
