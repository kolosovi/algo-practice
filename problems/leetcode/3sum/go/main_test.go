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
