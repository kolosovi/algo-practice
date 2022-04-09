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
package fruit_into_baskets

func totalFruit(fruits []int) int {
	older, newer := -1, -1
	maxCount := -1
	beforeLast, last := 0, 0
	for i, fruitType := range fruits {
		if newer == -1 {
			newer = fruitType
			continue
		}
		if older == -1 && newer != fruitType {
			// new element evicts the single present one
			older = newer
			newer = fruitType
			beforeLast = last
			last = i
			continue
		}
		if newer == fruitType {
			continue
		}
		if older == fruitType {
			// newer & older elements remain the same but change places
			older = newer
			newer = fruitType
			last = i
			continue
		}
		// new element evicts one of the two elements that were present
		older = newer
		newer = fruitType
		count := i - beforeLast
		if count > maxCount {
			maxCount = count
		}
		beforeLast = last
		last = i
	}
	count := len(fruits) - beforeLast
	if count > maxCount {
		maxCount = count
	}
	return maxCount
}
