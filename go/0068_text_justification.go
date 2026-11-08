package main

import "strings"

// 68. Text Justification

func concatLeftAligned(words []string, start, end, maxWidth int) string {
	var res strings.Builder
	res.Grow(maxWidth)
	res.WriteString(words[start])
	for i := start + 1; i < end; i++ {
		res.WriteRune(' ')
		res.WriteString(words[i])
	}
	res.WriteString(strings.Repeat(" ", maxWidth-res.Len()))
	return res.String()
}

func concatJustified(words []string, start, end, total, maxWidth int) string {
	nWords := end - start
	if nWords == 1 {
		return concatLeftAligned(words, start, end, maxWidth)
	}

	total -= nWords
	spaces := maxWidth - total
	minSpaces := spaces / (nWords - 1)
	extraSpaces := spaces % (nWords - 1)

	var res strings.Builder
	res.Grow(maxWidth)
	res.WriteString(words[start])
	for i := start + 1; i < end; i++ {
		spaceCount := minSpaces
		if extraSpaces > 0 {
			spaceCount++
			extraSpaces--
		}
		res.WriteString(strings.Repeat(" ", spaceCount))
		res.WriteString(words[i])
	}
	return res.String()
}

func fullJustify(words []string, maxWidth int) []string {
	result := []string{}
	length, start := 0, 0
	for i, word := range words {
		wlen := len(word) + 1
		length += wlen
		if length > maxWidth+1 {
			result = append(result, concatJustified(words, start, i, length-wlen, maxWidth))
			length, start = wlen, i
		}
	}
	if length > 0 {
		result = append(result, concatLeftAligned(words, start, len(words), maxWidth))
	}
	return result
}
