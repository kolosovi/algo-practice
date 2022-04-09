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
package expressivewords

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_expressiveWords(t *testing.T) {
	cases := []struct {
		s        string
		words    []string
		expected int
	}{
		{
			s:        "heeellooo",
			words:    []string{"hello", "hi", "helo"},
			expected: 1,
		},
		{
			s:        "zzzzzyyyyy",
			words:    []string{"zzyy", "zy", "zyy"},
			expected: 3,
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, expressiveWords(tc.s, tc.words))
		})
	}
}
