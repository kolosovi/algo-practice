package lengthoflis

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_lengthOfLIS(t *testing.T) {
	cases := []struct {
		nums     []int
		expected int
	}{
		{
			nums:     []int{4, 9, 5, 4, 3, 2, 9, 5, 3, 10},
			expected: 4,
		},
		{
			nums:     []int{9, 5, 4, 3, 2, 9, 5, 3, 10},
			expected: 3,
		},
		{
			nums:     []int{5, 4, 3, 2, 9, 5, 3, 10},
			expected: 3,
		},
		{
			nums:     []int{4, 3, 2, 9, 5, 3, 10},
			expected: 3,
		},
		{
			nums:     []int{3, 2, 9, 5, 3, 10},
			expected: 3,
		},
		{
			nums:     []int{2, 9, 5, 3, 10},
			expected: 3,
		},
		{
			nums:     []int{9, 5, 3, 10},
			expected: 2,
		},
		{
			nums:     []int{5, 3, 10},
			expected: 2,
		},
		{
			nums:     []int{3, 10},
			expected: 2,
		},
		{
			nums:     []int{10},
			expected: 1,
		},
		{
			nums:     []int{1, 8, 8, 3, 2, 1, 4, 1, 9, 1},
			expected: 4,
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, lengthOfLIS(tc.nums))
		})
	}
}
