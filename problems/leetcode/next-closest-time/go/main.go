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
	"sort"
)

func nextClosestTime(time string) string {
	hhmm := []int{
		int(time[0] - '0'),
		int(time[1] - '0'),
		int(time[3] - '0'),
		int(time[4] - '0'),
	}
	available := append(make([]int, 0, len(hhmm)), hhmm...)
	sort.Ints(available)
	maxes := []int{0: 2, 1: 3, 2: 5, 3: 9, 5: 9}
	min := 10
	for _, digit := range hhmm {
		if digit < min {
			min = digit
		}
	}
byPos:
	for i := 3; i >= 0; i-- {
		max := maxes[i]
		if hhmm[0] < 2 && i == 1 {
			max = maxes[5]
		}
		for _, digit := range available {
			if digit <= max && digit > hhmm[i] {
				hhmm[i] = digit
				break byPos
			}
		}
		hhmm[i] = min
	}
	return fmt.Sprintf("%d%d:%d%d", hhmm[0], hhmm[1], hhmm[2], hhmm[3])
}
