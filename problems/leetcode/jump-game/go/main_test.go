package jumpgame

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_canJump(t *testing.T) {
	cases := []struct {
		name     string
		nums     []int
		expected bool
	}{
		{
			name:     "example 1",
			nums:     []int{2, 3, 1, 1, 4},
			expected: true,
		},
		{
			name:     "example 2",
			nums:     []int{3, 2, 1, 0, 4},
			expected: false,
		},
		{
			name:     "instant win 1",
			nums:     []int{4},
			expected: true,
		},
		{
			name:     "instant win 2",
			nums:     []int{0},
			expected: true,
		},
		{
			name:     "biggie",
			nums:     makeBadCase(10000),
			expected: false,
		},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			require.Equal(t, tc.expected, canJump(tc.nums))
		})
	}
}

func makeBadCase(n int) []int {
	nums := make([]int, n)
	nums[len(nums)-1] = n - 1
	for i := 0; i < n-1; i++ {
		nums[len(nums)-i-2] = i
	}
	return nums
}
