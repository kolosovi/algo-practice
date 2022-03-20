package coinchange

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_coinChange(t *testing.T) {
	cases := []struct {
		coins    []int
		amount   int
		expected int
	}{
		{
			coins:    []int{1, 2, 5},
			amount:   11,
			expected: 3,
		},
		{
			coins:    []int{2},
			amount:   3,
			expected: -1,
		},
		{
			coins:    []int{1},
			amount:   0,
			expected: 0,
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, coinChange(tc.coins, tc.amount))
		})
	}
}
