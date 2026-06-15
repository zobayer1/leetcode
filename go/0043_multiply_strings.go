package main

import (
	"strconv"
	"strings"
)

// 43. Multiply Strings

func removeLeadingZeroes(num string) string {
	s := strings.TrimLeft(num, "0")
	if s == "" {
		return "0"
	}
	return s
}

func padLeft(num string, cnt int) string {
	if len(num) >= cnt {
		return num
	}
	return strings.Repeat("0", cnt-len(num)) + num
}

func add(num1, num2 string) string {
	var sb []byte
	i, j, carry := len(num1)-1, len(num2)-1, 0
	for i >= 0 || j >= 0 || carry > 0 {
		sum := carry
		if i >= 0 {
			sum += int(num1[i] - '0')
			i--
		}
		if j >= 0 {
			sum += int(num2[j] - '0')
			j--
		}
		sb = append(sb, byte(sum%10)+'0')
		carry = sum / 10
	}
	for i, j = 0, len(sb)-1; i < j; i, j = i+1, j-1 {
		sb[i], sb[j] = sb[j], sb[i]
	}
	return string(sb)
}

func sub(num1, num2 string) string {
	var sb []byte
	borrow := 0
	num2 = padLeft(num2, len(num1))
	for i := len(num1) - 1; i >= 0; i-- {
		diff := int(num1[i]-'0') - int(num2[i]-'0') - borrow
		if diff < 0 {
			diff += 10
			borrow = 1
		} else {
			borrow = 0
		}
		sb = append(sb, byte(diff)+'0')
	}
	for i, j := 0, len(sb)-1; i < j; i, j = i+1, j-1 {
		sb[i], sb[j] = sb[j], sb[i]
	}
	return string(sb)
}

func multiply(num1 string, num2 string) string {
	num1 = removeLeadingZeroes(num1)
	num2 = removeLeadingZeroes(num2)
	if num1 == "0" || num2 == "0" {
		return "0"
	}
	if len(num1) <= 9 && len(num2) <= 9 {
		n1, _ := strconv.Atoi(num1)
		n2, _ := strconv.Atoi(num2)
		return strconv.Itoa(n1 * n2)
	}
	n := max(len(num1), len(num2))
	num1 = padLeft(num1, n)
	num2 = padLeft(num2, n)

	mid := n / 2
	split := n - mid

	x1, x0 := num1[:mid], num1[mid:]
	y1, y0 := num2[:mid], num2[mid:]

	z2 := multiply(x1, y1)
	z0 := multiply(x0, y0)

	sx := add(x1, x0)
	sy := add(y1, y0)

	zr := multiply(sx, sy)
	z1 := removeLeadingZeroes(sub(sub(zr, z2), z0))

	term1 := z2 + strings.Repeat("0", split*2)
	term2 := z1 + strings.Repeat("0", split)

	return removeLeadingZeroes(add(add(term1, term2), z0))
}
