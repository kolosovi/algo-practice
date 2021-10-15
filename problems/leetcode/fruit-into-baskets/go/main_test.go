package fruit_into_baskets

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_totalFruit(t *testing.T) {
	cases := []struct {
		name     string
		fruits   []int
		expected int
	}{
		{
			name:     "example 1",
			fruits:   []int{1, 2, 1},
			expected: 3,
		},
		{
			name:     "example 2",
			fruits:   []int{0, 1, 2, 2},
			expected: 3,
		},
		{
			name:     "example 3",
			fruits:   []int{1, 2, 3, 2, 2},
			expected: 4,
		},
		{
			name:     "example 4",
			fruits:   []int{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4},
			expected: 5,
		},
		{
			name:     "example 5",
			fruits:   []int{0, 1, 6, 6, 4, 4, 6},
			expected: 5,
		},
	}
	for _, aCase := range cases {
		t.Run(aCase.name, func(t *testing.T) {
			actual := totalFruit(aCase.fruits)
			require.Equal(t, aCase.expected, actual)
		})
	}
}
