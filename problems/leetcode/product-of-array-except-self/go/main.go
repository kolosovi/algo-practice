package productexceptself

func productExceptSelf(nums []int) []int {
	left := make([]int, len(nums))
	left[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		left[i] = nums[i] * left[i-1]
	}
	r := 1
	for i := len(nums) - 1; i > 0; i-- {
		left[i] = left[i-1] * r
		r *= nums[i]
	}
	left[0] = r
	return left
}
