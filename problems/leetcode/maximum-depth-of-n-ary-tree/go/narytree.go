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
package narytree

type Node struct {
	Val      int
	Children []*Node
}

type PathItem struct {
	Node     *Node
	ChildIdx int
}

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	var result int
	path := []PathItem{{Node: root, ChildIdx: 0}}
	for len(path) > 0 {
		cur := path[len(path)-1]
		if cur.ChildIdx >= len(cur.Node.Children) {
			if cur.ChildIdx == 0 && len(path) > result {
				result = len(path)
			}
			path = path[:len(path)-1]
			continue
		}
		path[len(path)-1].ChildIdx++
		path = append(
			path,
			PathItem{
				Node:     cur.Node.Children[cur.ChildIdx],
				ChildIdx: 0,
			},
		)
	}
	return result
}
