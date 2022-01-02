package maximum_subarray

func maxSubArray(nums []int) int {
	max, sum := -10001, 0
	for _, num := range nums {
		if num > 0 && sum < 0 {
			sum = 0
		}
		if num <= 0 && num > max {
			max = num
		}
		sum += num
		if sum > max {
			max = sum
		}
	}
	return max
}
