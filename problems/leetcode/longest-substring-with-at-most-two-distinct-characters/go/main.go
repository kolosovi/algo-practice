package lengthoflongestsubstringtwodistinct

func lengthOfLongestSubstringTwoDistinct(s string) int {
	var max int
	var chars [2]byte
	var charCount int
	var seqStart, groupStart int

	for i := 0; i < len(s); i++ {
		var changed bool
		if i == 0 || s[i] != s[i-1] {
			changed = true
		}

		if charCount == 2 && s[i] != chars[0] && s[i] != chars[1] {
			chars[0], chars[1] = s[i], chars[0]
			seqStart = groupStart
		} else if charCount == 0 {
			chars[0] = s[i]
			charCount++
		} else if charCount == 2 && (s[i] == chars[0] || s[i] == chars[1]) && changed {
			chars[0], chars[1] = chars[1], chars[0]
		} else if charCount == 1 && changed {
			chars[0], chars[1] = s[i], chars[0]
			charCount++
		}

		if changed {
			groupStart = i
		}

		if length := i - seqStart + 1; length > max {
			max = length
		}
	}
	return max
}
