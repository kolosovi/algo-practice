package threesum

import (
	"testing"

	"github.com/google/go-cmp/cmp"
	"github.com/google/go-cmp/cmp/cmpopts"
	"github.com/stretchr/testify/require"
)

func Test_threeSum(t *testing.T) {
	cases := []struct {
		name     string
		nums     []int
		expected [][]int
	}{
		{
			name:     "example 1",
			nums:     []int{-1, 0, 1, 2, -1, -4},
			expected: [][]int{{-1, -1, 2}, {-1, 0, 1}},
		},
		{
			name:     "example 2",
			nums:     nil,
			expected: nil,
		},
		{
			name:     "example 3",
			nums:     []int{0},
			expected: nil,
		},
		{
			name:     "big test",
			nums:     make([]int, 3000),
			expected: [][]int{{0, 0, 0}},
		},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			require.Empty(
				t,
				cmp.Diff(
					tc.expected,
					threeSum(tc.nums),
					cmpopts.EquateEmpty(),
				),
			)
		})
	}
}
