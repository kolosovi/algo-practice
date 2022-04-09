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
package lengthoflis

func lengthOfLIS(nums []int) int {
	var lenNums, lens []int
	var maxLen int
	for i := len(nums) - 1; i >= 0; i-- {
		idx := binSearch(lenNums, nums[i])
		if idx == len(lenNums) {
			lenNums = append(lenNums, 0)
			lens = append(lens, 0)
		}
		newLen := 1
		if idx > 0 {
			newLen += lens[idx-1]
		}
		lenNums[idx] = nums[i]
		lens[idx] = newLen
		if newLen > maxLen {
			maxLen = newLen
		}
	}
	return maxLen
}

func binSearch(nums []int, target int) int {
	if len(nums) == 0 {
		return 0
	}
	l, r := 0, len(nums)-1
	for l <= r {
		m := (l + r) / 2
		if nums[m] <= target {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
