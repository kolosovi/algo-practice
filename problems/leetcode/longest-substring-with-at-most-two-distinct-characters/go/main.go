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
package lengthoflongestsubstringtwodistinct

func lengthOfLongestSubstringTwoDistinct(s string) int {
	var max int
	var chars [2]byte
	var charCount int
	var seqStart, groupStart int

	for i := 0; i < len(s); i++ {
		var changed bool
		if i == 0 || s[i] != s[i-1] {
			changed = true
		}

		if charCount == 2 && s[i] != chars[0] && s[i] != chars[1] {
			chars[0], chars[1] = s[i], chars[0]
			seqStart = groupStart
		} else if charCount == 0 {
			chars[0] = s[i]
			charCount++
		} else if charCount == 2 && (s[i] == chars[0] || s[i] == chars[1]) && changed {
			chars[0], chars[1] = chars[1], chars[0]
		} else if charCount == 1 && changed {
			chars[0], chars[1] = s[i], chars[0]
			charCount++
		}

		if changed {
			groupStart = i
		}

		if length := i - seqStart + 1; length > max {
			max = length
		}
	}
	return max
}
