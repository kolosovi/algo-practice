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
