package addbinary

func addBinary(a string, b string) string {
	if a == "0" {
		return b
	}
	if b == "0" {
		return a
	}
	var result []byte
	var carry byte
	for i := 0; i < len(a) || i < len(b) || carry > 0; i++ {
		next := carry
		if i < len(a) {
			next += a[len(a)-i-1] - '0'
		}
		if i < len(b) {
			next += b[len(b)-i-1] - '0'
		}
		carry = 0
		if next > 1 {
			carry = 1
			next = next % 2
		}
		result = append(result, next+'0')
	}
	for i, j := 0, len(result)-1; i < j; {
		result[i], result[j] = result[j], result[i]
		i++
		j--
	}
	return string(result)
}
