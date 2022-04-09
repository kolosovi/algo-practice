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
package maximum_subarray

func maxSubArray(nums []int) int {
	max, sum := -10001, 0
	for _, num := range nums {
		if num > 0 && sum < 0 {
			sum = 0
		}
		if num <= 0 && num > max {
			max = num
		}
		sum += num
		if sum > max {
			max = sum
		}
	}
	return max
}
