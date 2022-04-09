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
package multiplystrings

import (
	"strconv"
	"strings"
)

func multiply(num1 string, num2 string) string {
	if (len(num1) == 1 && num1[0] == '0') || (len(num2) == 1 && num2[0] == '0') {
		return "0"
	}
	var addendsReverse [10]string
	for i := range num2 {
		digit2 := int(num2[len(num2)-1-i] - '0')
		if addendsReverse[digit2] != "" {
			continue
		}
		if digit2 == 0 {
			addendsReverse[digit2] = "0"
			continue
		}
		var addendDigitsReverse []string
		var carry int
		for offset := 0; ; offset++ {
			newMul := carry
			if offset < len(num1) {
				newMul += digit2 * int(num1[len(num1)-1-offset]-'0')
			}
			if newMul == 0 && offset >= len(num1) {
				break
			}
			addendDigitsReverse = append(addendDigitsReverse, strconv.Itoa(newMul%10))
			carry = newMul / 10
		}
		addendsReverse[digit2] = strings.Join(addendDigitsReverse, "")
	}
	var resultDigitsReverse []int
	var carry int
	for offset := 0; ; offset++ {
		var added bool
		newSum := carry
		for digitInd := range num2 {
			digit := int(num2[len(num2)-1-digitInd] - '0')
			addendDigitPos := offset - digitInd
			if addendDigitPos >= 0 && addendDigitPos < len(addendsReverse[digit]) {
				newSum += int(addendsReverse[digit][addendDigitPos] - '0')
				added = true
			}
		}
		if newSum == 0 && !added {
			break
		}
		resultDigitsReverse = append(resultDigitsReverse, newSum%10)
		carry = newSum / 10
	}
	result := make([]byte, len(resultDigitsReverse))
	for i := range result {
		result[i] = '0' + byte(resultDigitsReverse[len(result)-1-i])
	}
	return string(result)
}
