package word_ladder

type solver struct {
	nodes     map[int][]int
	beginNode int
	endNode   int
}

type Node struct {
	Node  int
	Depth int
}

func (s *solver) solve() int {
	visited := map[int]struct{}{s.beginNode: {}}
	queue := []Node{{Node: s.beginNode, Depth: 1}}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		visited[node.Node] = struct{}{}
		if node.Node == s.endNode {
			return node.Depth
		}
		for _, child := range s.nodes[node.Node] {
			if _, ok := visited[child]; ok {
				continue
			}
			visited[child] = struct{}{}
			queue = append(queue, Node{Node: child, Depth: node.Depth + 1})
		}
	}
	return 0
}

func newSolver(beginWord string, endWord string, words []string) *solver {
	nodes := make(map[int][]int)
	beginNode, endNode := -1, -1
	for i := range words {
		if words[i] == beginWord {
			beginNode = i
		}
		if words[i] == endWord {
			endNode = i
		}
		for j := i + 1; j < len(words); j++ {
			if connected(words[i], words[j]) {
				nodes[i] = append(nodes[i], j)
				nodes[j] = append(nodes[j], i)
			}
		}
	}
	if beginNode == -1 {
		words = append(words, beginWord)
		beginNode = len(words) - 1
		for i := 0; i < beginNode; i++ {
			if connected(beginWord, words[i]) {
				nodes[beginNode] = append(nodes[beginNode], i)
				nodes[i] = append(nodes[i], beginNode)
			}
		}
	}
	return &solver{
		nodes:     nodes,
		beginNode: beginNode,
		endNode:   endNode,
	}
}

func connected(lhs, rhs string) bool {
	var wordsDiffer bool
	for j := range lhs {
		if lhs[j] != rhs[j] {
			if wordsDiffer {
				return false
			}
			wordsDiffer = true
		}
	}
	return wordsDiffer
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	solver := newSolver(beginWord, endWord, wordList)
	return solver.solve()
}
