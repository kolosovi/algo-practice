package climb_stairs

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_climbStairs(t *testing.T) {
	cases := []struct {
		n        int
		expected int
	}{
		{n: 1, expected: 1},
		{n: 2, expected: 2},
		{n: 3, expected: 3},
		{n: 5, expected: 8},
	}
	for _, tc := range cases {
		require.Equal(t, tc.expected, climbStairs(tc.n))
	}
}
