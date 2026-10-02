import "math"

func safe_calc(a, digit int) (int, bool) {
    if a > math.MaxInt32 / 10 {
        return 0, true
    }
    if a < math.MinInt32 / 10 {
        return 0, true
    }
    t := a * 10
    if digit > 0 && t > math.MaxInt32 - digit {
        return 0, true
    }
    if digit < 0 && t < math.MinInt32 - digit {
        return 0, true
    }
    return t + digit, false
}

func reverse(x int) int {
    var ret int = 0
    var overflow bool = false
    for x != 0 {
        ret, overflow = safe_calc(ret, x % 10)
        if overflow {
            return 0
        }
        x /= 10
    }
    return ret
}

