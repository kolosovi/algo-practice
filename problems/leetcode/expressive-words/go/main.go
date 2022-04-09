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
package expressivewords

func expressiveWords(s string, words []string) int {
	var groups []byte
	var lens []int
	var groupStart int
	for i := 1; i <= len(s); i++ {
		if i < len(s) && s[i] == s[groupStart] {
			continue
		}
		groups = append(groups, s[groupStart])
		lens = append(lens, i-groupStart)
		groupStart = i
	}

	var count int
byWords:
	for i := range words {
		var groupI int
		var wordGroupStart int
		for j := 0; j <= len(words[i]); j++ {
			if j < len(words[i]) && words[i][j] == words[i][wordGroupStart] {
				continue
			}
			switch {
			case groupI >= len(groups):
				continue byWords
			case groups[groupI] != words[i][wordGroupStart]:
				continue byWords
			case lens[groupI] <= 2 && j-wordGroupStart != lens[groupI]:
				continue byWords
			case lens[groupI] > 2 && j-wordGroupStart > lens[groupI]:
				continue byWords
			}
			wordGroupStart = j
			groupI++
		}
		if groupI == len(groups) {
			count++
		}
	}
	return count
}
