package main

// 30. Substring with Concatenation of All Words

var primebase = 31
var primemod = 1000000007

type WordHashes struct {
	hashes map[int]int
	need   []int
	seen   []int
	idx    []int
}

func modpow(n, p, m int) int {
	r := 1
	b := n % m
	for p > 0 {
		if p%2 == 1 {
			r = (r * b) % m
		}
		b = (b * b) % m
		p /= 2
	}
	return r
}

func rabinKarp(s string) int {
	h := 0
	for i := 0; i < len(s); i++ {
		h = (h*primebase + int(s[i])) % primemod
	}
	return h
}

func (w *WordHashes) generateHashes(words []string) {
	id := 1
	for _, word := range words {
		hash := rabinKarp(word)
		eid, found := w.hashes[hash]
		if !found {
			eid = id
			w.hashes[hash] = eid
			id++
		}
		w.need[eid]++
	}
}

func (w *WordHashes) rollingHashes(s string, l int) {
	n := len(s)
	h := 0
	high := modpow(primebase, l-1, primemod)
	for i := 0; i < n; i++ {
		if i >= l {
			h = ((h-int(s[i-l])*high)%primemod + primemod) % primemod
		}
		h = (h*primebase + int(s[i])) % primemod
		if i >= l-1 {
			id, found := w.hashes[h]
			if found {
				w.idx[i-l+1] = id
			}
		}
	}
}

func findSubstring(s string, words []string) []int {
	n := len(s)
	m := len(words)
	wlen := len(words[0])
	wh := WordHashes{
		hashes: make(map[int]int),
		need:   make([]int, m+1),
		seen:   make([]int, m+1),
		idx:    make([]int, n),
	}
	wh.generateHashes(words)
	wh.rollingHashes(s, wlen)
	results := []int{}
	for i := range wlen {
		left, right := i, i
		total := 0
		for ; right+wlen <= n; right += wlen {
			rid := wh.idx[right]
			if rid == 0 {
				for ; left <= right; left += wlen {
					lid := wh.idx[left]
					if lid > 0 {
						wh.seen[lid]--
						total--
					}
				}
				continue
			}
			wh.seen[rid]++
			total++
			for wh.seen[rid] > wh.need[rid] {
				lid := wh.idx[left]
				if lid > 0 {
					wh.seen[lid]--
					total--
				}
				left += wlen
			}
			if total == m {
				results = append(results, left)
				wh.seen[wh.idx[left]]--
				total--
				left += wlen
			}
		}
		for ; left < right; left += wlen {
			wh.seen[wh.idx[left]]--
		}
	}
	return results
}
