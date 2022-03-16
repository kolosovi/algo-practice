package jumpgame

func canJump(nums []int) bool {
	t := len(nums) - 1
	i := t
	for t > 0 && i > 0 {
		i--
		for ; i >= 0; i-- {
			if i+nums[i] >= t {
				t = i
				break
			}
		}
	}
	return t == 0
}
