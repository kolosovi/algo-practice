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
package nextclosesttime

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/require"
)

func Test_nextClosestTime(t *testing.T) {
	allTimes := calcAllTimes()
	cases := make([]testCase, 0, len(allTimes))
	for i := range allTimes {
		cases = append(cases, testCase{
			time:     allTimes[i],
			expected: nextTime(allTimes, i),
		})
	}
	for i, tc := range cases {
		t.Run(fmt.Sprintf("%d (%v)", i, tc.time), func(t *testing.T) {
			require.Equal(t, tc.expected, nextClosestTime(tc.time))
		})
	}
}

type testCase struct {
	time     string
	expected string
}

func calcAllTimes() []string {
	var times []string
	for hour := 0; hour < 24; hour++ {
		for minute := 0; minute < 60; minute++ {
			times = append(times, fmt.Sprintf("%02d:%02d", hour, minute))
		}
	}
	return times
}

func nextTime(allTimes []string, i int) string {
	for j := i + 1; j < len(allTimes); j++ {
		if isBuiltFrom(allTimes[j], allTimes[i]) {
			return allTimes[j]
		}
	}
	for j := 0; j < i; j++ {
		if isBuiltFrom(allTimes[j], allTimes[i]) {
			return allTimes[j]
		}
	}
	return allTimes[i]
}

func isBuiltFrom(time string, builtFrom string) bool {
	for i := 0; i < len(time); i++ {
		var matches bool
		for j := 0; j < len(builtFrom); j++ {
			if time[i] == builtFrom[j] {
				matches = true
				break
			}
		}
		if !matches {
			return false
		}
	}
	return true
}
