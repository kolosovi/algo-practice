package narytree

type Node struct {
    Val int
    Children []*Node
}

type PathItem struct {
    Node *Node
    ChildIdx int
}

func maxDepth(root *Node) int {
    if root == nil {
        return 0
    }
    var result int
    path := []PathItem{{Node: root, ChildIdx: 0}}
    for len(path) > 0 {
        cur := path[len(path) - 1]
        if cur.ChildIdx >= len(cur.Node.Children) {
            if cur.ChildIdx == 0 && len(path) > result {
                result = len(path)
            }
            path = path[:len(path) - 1]
            continue
        }
        path[len(path) - 1].ChildIdx++
        path = append(
            path,
            PathItem{
                Node: cur.Node.Children[cur.ChildIdx],
                ChildIdx: 0,
            },
        )
    }
    return result
}
