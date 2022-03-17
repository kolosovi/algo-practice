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
