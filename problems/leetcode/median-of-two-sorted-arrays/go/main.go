package median_of_two_sorted_arrays

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) == 0 {
		return Middle(nums2)
	}
	if len(nums2) == 0 {
		return Middle(nums1)
	}
	found, result := find(nums1, nums2)
	if found {
		return result
	}
	_, result = find(nums2, nums1)
	return result
}

func find(nums1, nums2 []int) (bool, float64) {
	left, right := 0, len(nums1)-1
	for left <= right {
		mid1 := (left + right) / 2
		mid2 := (len(nums1)+len(nums2))/2 - mid1
		if mid1 == len(nums1) {
			return true, CalcMedian(nums2, nums1, mid2, mid1)
		}
		hasLeftSurplus := HasLeftSurplus(nums1, nums2, mid1, mid2)
		hasRightSurplus := HasRightSurplus(nums1, nums2, mid1, mid2)
		if !hasLeftSurplus && !hasRightSurplus {
			return true, CalcMedian(nums1, nums2, mid1, mid2)
		}
		if mid2 >= 0 && mid2 < len(nums2) && !HasLeftSurplus(nums2, nums1, mid2, mid1) && !HasRightSurplus(nums2, nums1, mid2, mid1) {
			return true, CalcMedian(nums2, nums1, mid2, mid1)
		}
		if hasLeftSurplus {
			right = mid1
		} else {
			left = mid1 + 1
		}
	}
	return false, 0.0
}

func CalcMedian(medArr []int, arr []int, medI int, i int) float64 {
	if (len(medArr)+len(arr))%2 == 1 {
		return float64(medArr[medI])
	}
	if medI != 0 && (i == 0 || medArr[medI-1] > arr[i-1]) {
		return float64(medArr[medI]+medArr[medI-1]) / 2.0
	}
	return float64(medArr[medI]+arr[i-1]) / 2.0
}

func HasLeftSurplus(medArr, arr []int, medI, i int) bool {
	if i < 0 {
		return true
	}
	return i >= 0 && i < len(arr) && arr[i] < medArr[medI]
}

func HasRightSurplus(medArr, arr []int, medI, i int) bool {
	if i > len(arr) {
		return true
	}
	return (i-1) >= 0 && (i-1) < len(arr) && arr[i-1] > medArr[medI]
}

func Middle(nums []int) float64 {
	if len(nums)%2 == 1 {
		return float64(nums[len(nums)/2])
	}
	return 0.5 * float64(nums[len(nums)/2]+nums[len(nums)/2-1])
}
