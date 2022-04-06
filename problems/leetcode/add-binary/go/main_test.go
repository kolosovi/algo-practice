package addbinary

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_addBinary(t *testing.T) {
	cases := []struct {
		a        string
		b        string
		expected string
	}{
		{
			a:        "11111",
			b:        "0",
			expected: "11111",
		},
		{
			a:        "0",
			b:        "11111",
			expected: "11111",
		},
		{
			a:        "11",
			b:        "1",
			expected: "100",
		},
		{
			a:        "1010",
			b:        "1011",
			expected: "10101",
		},
	}
	for i, tc := range cases {
		t.Run(strconv.Itoa(i), func(t *testing.T) {
			require.Equal(t, tc.expected, addBinary(tc.a, tc.b))
		})
	}
}
