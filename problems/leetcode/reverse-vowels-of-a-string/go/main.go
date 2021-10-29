package reverse_vowels_of_a_string

var isVowel = [127]bool{
	'a': true,
	'e': true,
	'i': true,
	'o': true,
	'u': true,
	'A': true,
	'E': true,
	'I': true,
	'O': true,
	'U': true,
}

func reverseVowels(s string) string {
	ret := []byte(s)
	l, r := 0, len(ret)-1
	for l < r {
		if isVowel[ret[l]] && isVowel[ret[r]] {
			ret[l], ret[r] = ret[r], ret[l]
			l++
			r--
			continue
		}
		if !isVowel[ret[l]] {
			l++
		}
		if !isVowel[ret[r]] {
			r--
		}
	}
	return string(ret)
}
