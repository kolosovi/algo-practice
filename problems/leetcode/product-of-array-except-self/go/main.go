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
package productexceptself

func productExceptSelf(nums []int) []int {
	left := make([]int, len(nums))
	left[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		left[i] = nums[i] * left[i-1]
	}
	r := 1
	for i := len(nums) - 1; i > 0; i-- {
		left[i] = left[i-1] * r
		r *= nums[i]
	}
	left[0] = r
	return left
}
