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
package lc_unique_email_addresses

import (
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_numUniqueEmails(t *testing.T) {
	cases := []struct {
		emails   []string
		expected int
	}{
		{
			emails: []string{
				"test.email+alex@leetcode.com",
				"test.e.mail+bob.cathy@leetcode.com",
				"testemail+david@lee.tcode.com",
			},
			expected: 2,
		},
		{
			emails: []string{
				"a@leetcode.com",
				"b@leetcode.com",
				"c@leetcode.com",
			},
			expected: 3,
		},
	}
	for _, tc := range cases {
		t.Run(strings.Join(tc.emails, ", "), func(t *testing.T) {
			require.Equal(t, tc.expected, numUniqueEmails(tc.emails))
		})
	}
}
