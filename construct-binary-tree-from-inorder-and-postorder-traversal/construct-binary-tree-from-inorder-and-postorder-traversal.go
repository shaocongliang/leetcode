/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getIndex(nums []int, target int) int {
  for i := 0; i < len(nums); i++ {
    if nums[i] == target {
      return i;
    }
  }
  return -1;
}

func buildTree(io []int, po []int) *TreeNode {
  l1 := len(io)
  l2 := len(po)
  
  if l1 == 0 || l2 == 0 {
    return nil;
  }
  
  val := po[l2-1]
  index := getIndex(io, val)
  node := new(TreeNode)
  node.Val = val
  
  if index == 0 {
    node.Left = nil
    node.Right = buildTree(io[index+1:], po[:l2-1])
  } else if index + 1 > l1 -1 {
    node.Right = nil
    node.Left = buildTree(io[:index], po[:index])
  } else {
    node.Left = buildTree(io[:index], po[:index])
    node.Right = buildTree(io[index+1:], po[index:l1-1])
  }
  return node
}
