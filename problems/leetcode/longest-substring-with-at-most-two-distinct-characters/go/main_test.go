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
package lengthoflongestsubstringtwodistinct

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_lengthOfLongestSubstringTwoDistinct(t *testing.T) {
	cases := []struct {
		name     string
		s        string
		expected int
	}{
		{
			name:     "example 1",
			s:        "eceba",
			expected: 3,
		},
		{
			name:     "example 2",
			s:        "ccaabbb",
			expected: 5,
		},
		{
			name:     "example 3",
			s:        "cacabbb",
			expected: 4,
		},
		{
			name:     "hitro",
			s:        "cdaba",
			expected: 3,
		},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			require.Equal(t, tc.expected, lengthOfLongestSubstringTwoDistinct(tc.s))
		})
	}
}
