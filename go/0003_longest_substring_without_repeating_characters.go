func lengthOfLongestSubstring(s string) int {
    last_seen := [128]int{}
    var left, max_len int = 0, 0
    for right, ch := range s {
        if last_seen[int(ch)] > left {
            left = last_seen[int(ch)]
        }
        last_seen[int(ch)] = right + 1
        max_len = max(max_len, right - left + 1)
    }
    return max_len
}
