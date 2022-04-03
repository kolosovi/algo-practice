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
