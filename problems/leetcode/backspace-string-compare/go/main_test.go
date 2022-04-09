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
package backspacecompare

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_backspaceCompare(t *testing.T) {
	cases := []struct {
		s        string
		t        string
		expected bool
	}{
		{
			s:        "ab#c",
			t:        "ad#c",
			expected: true,
		},
		{
			s:        "ab##",
			t:        "c#d#",
			expected: true,
		},
		{
			s:        "a#c",
			t:        "b",
			expected: false,
		},
		{
			s:        "###",
			t:        "######",
			expected: true,
		},
		{
			s:        "###abc",
			t:        "######abc",
			expected: true,
		},
		{
			s:        "###abc",
			t:        "######",
			expected: false,
		},
		{
			s:        "###",
			t:        "######abc",
			expected: false,
		},
		{
			s:        "bxj##tw",
			t:        "bxj###tw",
			expected: false,
		},
		{
			s:        "nzp#o#g",
			t:        "b#nzp#o#g",
			expected: true,
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, backspaceCompare(tc.s, tc.t))
		})
	}
}
