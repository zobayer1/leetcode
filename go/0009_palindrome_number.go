func isPalindrome(x int) bool {
    if x < 0 {
        return false
    }
    var r, p int = 0, x
    for x != 0 {
        r = r * 10 + x % 10
        x /= 10
    }

    return r == p
}
