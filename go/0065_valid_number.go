package main

// 65. Valid Number

type Solution struct {
	input string
	pos   int
}

func (sol *Solution) peek() (byte, bool) {
	if sol.pos < len(sol.input) {
		return sol.input[sol.pos], true
	}
	return 0, false
}

func (sol *Solution) isDigit() bool {
	pk, ok := sol.peek()
	return ok && pk >= '0' && pk <= '9'
}

func (sol *Solution) consume(c byte) bool {
	pk, ok := sol.peek()
	if !ok || pk != c {
		return false
	}
	sol.pos++
	return true
}

func (sol *Solution) consumed() bool {
	return sol.pos == len(sol.input)
}

func (sol *Solution) parseSign() bool {
	return sol.consume('+') || sol.consume('-')
}

func (sol *Solution) parseDigits() bool {
	if !sol.isDigit() {
		return false
	}
	for sol.isDigit() {
		sol.pos++
	}
	return true
}

func (sol *Solution) parseUnsignedNumber() bool {
	if sol.parseDigits() {
		if sol.consume('.') {
			_ = sol.parseDigits()
		}
		return true
	}
	if sol.consume('.') {
		return sol.parseDigits()
	}
	return false
}

func (sol *Solution) parseExponent() bool {
	if !sol.consume('e') && !sol.consume('E') {
		return false
	}
	_ = sol.parseSign()
	return sol.parseDigits()
}

func (sol *Solution) parseNumber() bool {
	_ = sol.parseSign()
	if !sol.parseUnsignedNumber() {
		return false
	}
	pk, ok := sol.peek()
	if ok && (pk == 'e' || pk == 'E') {
		return sol.parseExponent()
	}
	return true
}

func isNumber(s string) bool {
	sol := Solution{input: s, pos: 0}
	return sol.parseNumber() && sol.consumed()
}
