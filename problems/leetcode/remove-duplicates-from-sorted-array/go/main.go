package removeduplicates

func removeDuplicates(nums []int) int {
	k := 0
	for i := 1; i <= len(nums); i++ {
		if i == len(nums) || nums[i] != nums[i-1] {
			nums[k] = nums[i-1]
			k++
		}
	}
	return k
}
