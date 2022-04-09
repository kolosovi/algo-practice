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
package symmetric_tree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isSymmetricRec(root.Left, root.Right)
}

func isSymmetricRec(a, b *TreeNode) bool {
	if a == nil && b != nil || a != nil && b == nil {
		return false
	}
	if a == nil {
		return true
	}
	if a.Val != b.Val {
		return false
	}
	if !isSymmetricRec(a.Left, b.Right) {
		return false
	}
	return isSymmetricRec(a.Right, b.Left)
}
