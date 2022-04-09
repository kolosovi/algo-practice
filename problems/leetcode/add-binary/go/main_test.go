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
package addbinary

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_addBinary(t *testing.T) {
	cases := []struct {
		a        string
		b        string
		expected string
	}{
		{
			a:        "11111",
			b:        "0",
			expected: "11111",
		},
		{
			a:        "0",
			b:        "11111",
			expected: "11111",
		},
		{
			a:        "11",
			b:        "1",
			expected: "100",
		},
		{
			a:        "1010",
			b:        "1011",
			expected: "10101",
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, addBinary(tc.a, tc.b))
		})
	}
}
