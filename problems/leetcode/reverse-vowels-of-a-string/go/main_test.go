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
