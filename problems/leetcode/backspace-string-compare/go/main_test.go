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
