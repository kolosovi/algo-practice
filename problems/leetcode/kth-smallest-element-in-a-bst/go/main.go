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
package kth_smallest_element_in_a_bst

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func kthSmallest(root *TreeNode, k int) int {
	var path []*TreeNode
	cur := root
	for cur.Left != nil {
		path = append(path, cur)
		cur = cur.Left
	}
	for i := 1; i < k; i++ {
		if cur.Right != nil {
			cur = cur.Right
			for cur.Left != nil {
				path = append(path, cur)
				cur = cur.Left
			}
		} else {
			cur = path[len(path)-1]
			path = path[:len(path)-1]
		}
	}
	return cur.Val
}
