func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    var n1, n2 = len(nums1), len(nums2)
    var mid, odd = (n1 + n2) / 2, (n1 + n2) % 2
    var sum = 0
    for i, j, k := 0, 0, 0; i < n1 || j < n2; k++ {
        var val int
        if i == n1 {
            val = nums2[j]
            j++
        } else if j == n2 {
            val = nums1[i]
            i++
        } else if nums1[i] < nums2[j] {
            val = nums1[i]
            i++
        } else {
            val = nums2[j]
            j++
        }
        if k == mid - 1 && odd == 0 {
            sum += val
        }
        if k == mid {
            sum += val
            break
        }
    }
    if odd == 1 {
        return float64(sum)
    }
    return float64(sum) / 2.0
}

