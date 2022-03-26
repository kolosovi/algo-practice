package lengthoflis

func lengthOfLIS(nums []int) int {
	var lenNums, lens []int
	var maxLen int
	for i := len(nums) - 1; i >= 0; i-- {
		idx := binSearch(lenNums, nums[i])
		if idx == len(lenNums) {
			lenNums = append(lenNums, 0)
			lens = append(lens, 0)
		}
		newLen := 1
		if idx > 0 {
			newLen += lens[idx-1]
		}
		lenNums[idx] = nums[i]
		lens[idx] = newLen
		if newLen > maxLen {
			maxLen = newLen
		}
	}
	return maxLen
}

func binSearch(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}
	l, r := 0, len(nums)-1
	for l <= r {
		m := (l + r) / 2
		if nums[m] <= target {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
