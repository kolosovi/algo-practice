package median_of_two_sorted_arrays

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestFindMedianSortedArrays(t *testing.T) {
	cases := []struct {
		desc     string
		nums1    []int
		nums2    []int
		expected float64
	}{
		{
			desc:     "first array has single element, second array is empty",
			nums1:    []int{5},
			expected: float64(5.0),
		},
		{
			desc:     "first array has odd length, second array is empty",
			nums1:    []int{5, 6, 7},
			expected: float64(6.0),
		},
		{
			desc:     "first array has even length, second array is empty",
			nums1:    []int{5, 6},
			expected: float64(5.5),
		},
		{
			desc:     "first array is empty, second array has single element",
			nums2:    []int{5},
			expected: float64(5.0),
		},
		{
			desc:     "first array is empty, second array has odd length",
			nums2:    []int{5, 6, 7},
			expected: float64(6.0),
		},
		{
			desc:     "first array is empty, second array has even length",
			nums2:    []int{5, 6},
			expected: float64(5.5),
		},
		{
			desc:     "leetcode example 1",
			nums1:    []int{1, 3},
			nums2:    []int{2},
			expected: float64(2.0),
		},
		{
			desc:     "leetcode example 2",
			nums1:    []int{1, 2},
			nums2:    []int{3, 4},
			expected: float64(2.5),
		},
		{
			desc:     "leetcode example 3",
			nums1:    []int{0, 0},
			nums2:    []int{0, 0},
			expected: float64(0.0),
		},
		{
			desc:     "going over second array limits while binsearching the first one",
			nums1:    []int{1, 2, 3, 5, 6, 7},
			nums2:    []int{4},
			expected: float64(4.0),
		},
	}
	for _, aCase := range cases {
		t.Run(aCase.desc, func(t *testing.T) {
			actual := findMedianSortedArrays(aCase.nums1, aCase.nums2)
			require.Equal(t, aCase.expected, actual)
		})
	}
}
