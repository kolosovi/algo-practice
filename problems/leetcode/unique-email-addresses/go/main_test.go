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
