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
