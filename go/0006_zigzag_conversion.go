func convert(s string, numRows int) string {
    sv := make([]strings.Builder, numRows)
    var row, rd int = 0, 1
    for _, ch := range s {
        sv[row].WriteRune(ch)
        if row + rd == numRows {
            rd *= -1
        }
        if row + rd < 0 {
            rd *= -1
        }
        if numRows > 1 {
            row += rd
        }
    }
    var result strings.Builder
    result.Grow(len(s))
    for _, t := range sv {
        result.WriteString(t.String())
    }
    return result.String()
}
