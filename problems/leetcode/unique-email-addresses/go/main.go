package lc_unique_email_addresses

func numUniqueEmails(emails []string) int {
	visited := make(map[string]struct{})
	for _, email := range emails {
		visited[normalize(email)] = struct{}{}
	}
	return len(visited)
}

func normalize(email string) string {
	const (
		stateLocal = iota
		stateLocalTail
		stateDomain
	)
	state := stateLocal
	result := make([]byte, 0, len(email))
	for i := 0; i < len(email); i++ {
		ch := email[i]
		switch state {
		case stateLocal:
			if ch == '.' {
				continue
			}
			if ch == '+' {
				state = stateLocalTail
				continue
			}
			result = append(result, ch)
			if ch == '@' {
				state = stateDomain
			}
		case stateLocalTail:
			if ch == '@' {
				result = append(result, ch)
				state = stateDomain
			}
		case stateDomain:
			result = append(result, ch)
		}
	}
	return string(result)
}
