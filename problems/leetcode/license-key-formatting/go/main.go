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
package license_key_formatting

func licenseKeyFormatting(s string, k int) string {
	var result []byte
	var offset int
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '-' {
			continue
		}
		if offset == 0 && len(result) > 0 {
			result = append(result, '-')
		}
		result = append(result, normalize(s[i]))
		offset = (offset + 1) % k
	}
	for left, right := 0, len(result)-1; left < right; {
		result[left], result[right] = result[right], result[left]
		left++
		right--
	}
	return string(result)
}

func normalize(ch byte) byte {
	if ch < 'a' {
		return ch
	}
	return ch - ('a' - 'A')
}
