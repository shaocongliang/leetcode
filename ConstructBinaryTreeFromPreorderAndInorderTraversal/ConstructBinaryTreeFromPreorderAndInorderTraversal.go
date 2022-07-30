/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func getIndex(inorder []int, val int) int {
    for i := 0; i < len(inorder); i++ {
        if inorder[i] == val {
            return i;
        }
    }
    return -1;
}
func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(inorder) == 0 {
        return nil;
    }
    if len(preorder) == 0 {
        return nil;
    }
    var node TreeNode
    node.Val = preorder[0]
    index := getIndex(inorder, preorder[0])
    if index != -1 {
        node.Left = buildTree(preorder[1:1+index], inorder[0:index])
        node.Right = buildTree(preorder[index+1:], inorder[index+1:])
    }
    return &node;
}
