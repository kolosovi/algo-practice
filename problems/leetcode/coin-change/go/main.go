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
package coinchange

import (
	"sort"
)

func coinChange(coins []int, amount int) int {
	sort.Ints(coins)
	solutions := make([]int, amount+1)
	for i := 1; i < len(solutions); i++ {
		solutions[i] = -2
	}
	return solve(coins, solutions, amount)
}

func solve(coins, solutions []int, amount int) int {
	if solutions[amount] != -2 {
		return solutions[amount]
	}
	result := -1
	for i := len(coins) - 1; i >= 0; i-- {
		if coins[i] > amount {
			continue
		}
		subsolution := solve(coins, solutions, amount-coins[i])
		if subsolution == -1 {
			continue
		}
		if solution := 1 + subsolution; result == -1 || solution < result {
			result = solution
		}
	}
	solutions[amount] = result
	return result
}
