package hindex

func hIndex(citations []int) int {
	countFreqs := make([]int, len(citations)+1)
	for _, count := range citations {
		if count > len(citations) {
			count = len(citations)
		}
		countFreqs[count]++
	}
	var count, cumFreq int
	for count = len(countFreqs) - 1; count >= 0; count-- {
		cumFreq += countFreqs[count]
		if cumFreq >= count {
			break
		}
	}
	return count
}
