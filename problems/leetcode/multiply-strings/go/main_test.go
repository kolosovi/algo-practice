package multiplystrings

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_multiply(t *testing.T) {
	cases := []struct {
		name     string
		num1     string
		num2     string
		expected string
	}{
		{
			name:     "zero 1",
			num1:     "0",
			num2:     "123456789",
			expected: "0",
		},
		{
			name:     "zero 2",
			num1:     "123456789",
			num2:     "0",
			expected: "0",
		},
		{
			name:     "example 1",
			num1:     "2",
			num2:     "3",
			expected: "6",
		},
		{
			name:     "example 2",
			num1:     "123",
			num2:     "456",
			expected: "56088",
		},
		{
			name:     "example 3",
			num1:     "408",
			num2:     "5",
			expected: "2040",
		},
		{
			name:     "example 4",
			num1:     "5",
			num2:     "408",
			expected: "2040",
		},
		{
			name:     "example 5",
			num1:     "1000000001",
			num2:     "2",
			expected: "2000000002",
		},
		{
			name:     "example 5",
			num1:     "2",
			num2:     "1000000001",
			expected: "2000000002",
		},
	}
	for _, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			require.Equal(t, tc.expected, multiply(tc.num1, tc.num2))
		})
	}
}
