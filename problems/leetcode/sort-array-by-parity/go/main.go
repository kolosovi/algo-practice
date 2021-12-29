package lc_sort_array_by_parity

func sortArrayByParity(nums []int) []int {
	var writeI int
	for i, num := range nums {
		if num%2 == 0 {
			nums[writeI], nums[i] = nums[i], nums[writeI]
			writeI++
		}
	}
	return nums
}
