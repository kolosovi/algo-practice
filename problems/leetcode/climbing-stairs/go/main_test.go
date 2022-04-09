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
