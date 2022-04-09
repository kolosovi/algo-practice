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
package backspacecompare

func backspaceCompare(s string, t string) bool {
	var sDeleteCount, tDeleteCount int
	i, j := len(s)-1, len(t)-1
	for i >= 0 || j >= 0 {
		for i >= 0 && (sDeleteCount > 0 || s[i] == '#') {
			if s[i] != '#' {
				sDeleteCount--
			} else {
				sDeleteCount++
			}
			i--
		}
		for j >= 0 && (tDeleteCount > 0 || t[j] == '#') {
			if t[j] != '#' {
				tDeleteCount--
			} else {
				tDeleteCount++
			}
			j--
		}
		if i < 0 && j < 0 {
			return true
		}
		if i >= 0 && j >= 0 {
			if s[i] != t[j] {
				return false
			}
			i--
			j--
		} else if i < 0 && t[j] != '#' {
			return false
		} else if j < 0 && s[i] != '#' {
			return false
		}
	}
	return i < 0 && j < 0
}
