package productexceptself

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_productExceptSelf(t *testing.T) {
	cases := []struct {
		nums     []int
		expected []int
	}{
		{
			nums:     []int{1, 2, 3, 4},
			expected: []int{24, 12, 8, 6},
		},
		{
			nums:     []int{-1, 1, 0, -3, 3},
			expected: []int{0, 0, 9, 0, 0},
		},
	}
	for _, tc := range cases {
		t.Run(fmt.Sprintf("%v", tc.nums), func(t *testing.T) {
			require.Equal(t, tc.expected, productExceptSelf(tc.nums))
		})
	}
}
