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
package license_key_formatting

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_licenseKeyFormatting(t *testing.T) {
	cases := []struct {
		s        string
		k        int
		expected string
	}{
		{
			s:        "5F3Z-2e-9-w",
			k:        4,
			expected: "5F3Z-2E9W",
		},
		{
			s:        "2-5g-3-J",
			k:        2,
			expected: "2-5G-3J",
		},
		{
			s:        "--abcdef--",
			k:        1,
			expected: "A-B-C-D-E-F",
		},
	}
	for _, tc := range cases {
		t.Run(fmt.Sprintf("s=%v, k=%v", tc.s, tc.k), func(t *testing.T) {
			require.Equal(t, tc.expected, licenseKeyFormatting(tc.s, tc.k))
		})
	}
}
