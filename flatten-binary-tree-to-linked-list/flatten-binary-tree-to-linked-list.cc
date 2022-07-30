/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(node *TreeNode)  {
    if node == nil {
        return 
    }
    l := newFlatten(node.Left)
    newFlatten(node.Right)
    if node.Left != nil {
        if node.Right != nil {
            tmp := node.Right
            node.Right = node.Left
            l.Right = tmp
            node.Left = nil
        } else {
            node.Right = node.Left;
            node.Left = nil
        }
    }
}

func newFlatten(node *TreeNode) *TreeNode {
    if node == nil {
        return nil
    }
    if node.Left != nil && node.Right != nil {
        leftSentry := newFlatten(node.Left)
        rightSentry := newFlatten(node.Right)
        tmp := node.Right
        node.Right = node.Left
        leftSentry.Right = tmp
        node.Left = nil
        return rightSentry
    } else if node.Left != nil && node.Right == nil {
        leftSentry := newFlatten(node.Left)
        node.Right = node.Left
        node.Left = nil
        return leftSentry;
    } else if node.Left == nil && node.Right != nil {
        rightSentry := newFlatten(node.Right)
        return rightSentry;
    } else {
        return node;
    }
}

