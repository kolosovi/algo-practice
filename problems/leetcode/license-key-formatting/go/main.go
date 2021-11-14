package license_key_formatting

func licenseKeyFormatting(s string, k int) string {
	var result []byte
	var offset int
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '-' {
			continue
		}
		if offset == 0 && len(result) > 0 {
			result = append(result, '-')
		}
		result = append(result, normalize(s[i]))
		offset = (offset + 1) % k
	}
	for left, right := 0, len(result)-1; left < right; {
		result[left], result[right] = result[right], result[left]
		left++
		right--
	}
	return string(result)
}

func normalize(ch byte) byte {
	if ch < 'a' {
		return ch
	}
	return ch - ('a' - 'A')
}
