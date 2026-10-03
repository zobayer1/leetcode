func twoSum(nums []int, target int) []int {
    seen := make(map[int]int, len(nums))
    for i, num:= range nums {
        r := target - num
        if val, ok := seen[r]; ok {
            return []int{i, val}
        }
        seen[num] = i
    }
    return []int{}
}
