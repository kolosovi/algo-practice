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
