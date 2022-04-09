// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
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
