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
package reverse_vowels_of_a_string

var isVowel = [127]bool{
	'a': true,
	'e': true,
	'i': true,
	'o': true,
	'u': true,
	'A': true,
	'E': true,
	'I': true,
	'O': true,
	'U': true,
}

func reverseVowels(s string) string {
	ret := []byte(s)
	l, r := 0, len(ret)-1
	for l < r {
		if isVowel[ret[l]] && isVowel[ret[r]] {
			ret[l], ret[r] = ret[r], ret[l]
			l++
			r--
			continue
		}
		if !isVowel[ret[l]] {
			l++
		}
		if !isVowel[ret[r]] {
			r--
		}
	}
	return string(ret)
}
