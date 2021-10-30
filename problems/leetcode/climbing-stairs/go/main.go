package climb_stairs

func climbStairs(n int) int {
	prev, cur := 0, 1
	for n > 0 {
		prev, cur = cur, prev+cur
		n--
	}
	return cur
}
