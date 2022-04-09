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
package hindex

func hIndex(citations []int) int {
	countFreqs := make([]int, len(citations)+1)
	for _, count := range citations {
		if count > len(citations) {
			count = len(citations)
		}
		countFreqs[count]++
	}
	var count, cumFreq int
	for count = len(countFreqs) - 1; count >= 0; count-- {
		cumFreq += countFreqs[count]
		if cumFreq >= count {
			break
		}
	}
	return count
}
