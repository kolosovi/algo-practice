package expressivewords

func expressiveWords(s string, words []string) int {
	var groups []byte
	var lens []int
	var groupStart int
	for i := 1; i <= len(s); i++ {
		if i < len(s) && s[i] == s[groupStart] {
			continue
		}
		groups = append(groups, s[groupStart])
		lens = append(lens, i-groupStart)
		groupStart = i
	}

	var count int
byWords:
	for i := range words {
		var groupI int
		var wordGroupStart int
		for j := 0; j <= len(words[i]); j++ {
			if j < len(words[i]) && words[i][j] == words[i][wordGroupStart] {
				continue
			}
			switch {
			case groupI >= len(groups):
				continue byWords
			case groups[groupI] != words[i][wordGroupStart]:
				continue byWords
			case lens[groupI] <= 2 && j-wordGroupStart != lens[groupI]:
				continue byWords
			case lens[groupI] > 2 && j-wordGroupStart > lens[groupI]:
				continue byWords
			}
			wordGroupStart = j
			groupI++
		}
		if groupI == len(groups) {
			count++
		}
	}
	return count
}
