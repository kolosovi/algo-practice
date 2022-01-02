package maximum_subarray

import (
	"strconv"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_maxSubArray(t *testing.T) {
	cases := []struct {
		nums     []int
		expected int
	}{
		{
			nums:     []int{-2, 1, -3, 4, -1, 2, 1, -5, 4},
			expected: 6,
		},
		{
			nums:     []int{1},
			expected: 1,
		},
		{
			nums:     []int{-3, -1, -2},
			expected: -1,
		},
		{
			nums:     []int{5, 4, -1, 7, 8},
			expected: 23,
		},
		{
			nums:     []int{-1, 2, 4, -3, 5, 2, -5, 2},
			expected: 10,
		},
	}
	for _, tc := range cases {
		t.Run(formatArr(tc.nums), func(t *testing.T) {
			require.Equal(t, tc.expected, maxSubArray(tc.nums))
		})
	}
}

func formatArr(arr []int) string {
	formattedElements := make([]string, 0, len(arr))
	for _, element := range arr {
		formattedElements = append(formattedElements, strconv.Itoa(element))
	}
	return strings.Join(formattedElements, ",")
}
