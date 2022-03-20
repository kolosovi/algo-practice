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
