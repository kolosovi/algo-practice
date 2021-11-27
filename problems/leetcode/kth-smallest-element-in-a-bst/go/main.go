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
