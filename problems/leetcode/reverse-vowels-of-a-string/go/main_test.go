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
package reverse_vowels_of_a_string

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_reverseVowels(t *testing.T) {
	cases := []struct {
		input    string
		expected string
	}{
		{
			input:    "hello",
			expected: "holle",
		},
		{
			input:    "leetcode",
			expected: "leotcede",
		},
		{
			input:    "lEetcOde",
			expected: "leOtcedE",
		},
	}
	for _, tc := range cases {
		t.Run(tc.input, func(t *testing.T) {
			require.Equal(t, tc.expected, reverseVowels(tc.input))
		})
	}
}
