package word_ladder

type solver struct {
	beginWord          string
	endWord            string
	replacementToWords map[string][]string
	wordToReplacements map[string][]string
}

func (s *solver) solve() int {
	visited := map[string]struct{}{s.beginWord: {}}
	depth := 1
	queue := []string{s.beginWord}
	for len(queue) > 0 {
		queueSize := len(queue)
		for ; queueSize > 0; queueSize-- {
			word := queue[0]
			queue = queue[1:]
			visited[word] = struct{}{}
			if word == s.endWord {
				return depth
			}
			children := s.children(word)
			for _, child := range children {
				if _, ok := visited[child]; ok {
					continue
				}
				visited[child] = struct{}{}
				queue = append(queue, child)
			}
		}
		depth++
	}
	return 0
}

func (s *solver) children(word string) []string {
	var result []string
	for _, replacement := range s.wordToReplacements[word] {
		for _, child := range s.replacementToWords[replacement] {
			if child == word {
				continue
			}
			result = append(result, child)
		}
	}
	return result
}

func newSolver(beginWord string, endWord string, words []string) *solver {
	replacementToWords := make(map[string][]string)
	wordToReplacements := make(map[string][]string)
	words = append(words, beginWord)
	for i := range words {
		replacements := make([]string, 0, len(words[i]))
		template := []byte(words[i])
		var prevChar byte
		for i := range template {
			if i > 0 {
				template[i-1] = prevChar
			}
			prevChar, template[i] = template[i], '_'
			replacements = append(replacements, string(template))
		}
		for _, replacement := range replacements {
			wordToReplacements[words[i]] = append(
				wordToReplacements[words[i]],
				replacement,
			)
			replacementToWords[replacement] = append(
				replacementToWords[replacement],
				words[i],
			)
		}
	}
	return &solver{
		beginWord:          beginWord,
		endWord:            endWord,
		replacementToWords: replacementToWords,
		wordToReplacements: wordToReplacements,
	}
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	solver := newSolver(beginWord, endWord, wordList)
	return solver.solve()
}
