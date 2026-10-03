func intToRoman(num int) string {
    var (
        val = [13]int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
        rom = [13][]byte{
            []byte("M"), []byte("CM"), []byte("D"), []byte("CD"),
            []byte("C"), []byte("XC"), []byte("L"), []byte("XL"),
            []byte("X"), []byte("IX"), []byte("V"), []byte("IV"),
            []byte("I"),
        }
    )
    buf := make([]byte, 0, 15)
    for i := 0; num > 0; i++ {
        for num >= val[i] {
            buf = append(buf, rom[i]...)
            num -= val[i]
        }
    }
    return string(buf)
}
