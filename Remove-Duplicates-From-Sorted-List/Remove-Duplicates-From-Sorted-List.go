/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	cur := head
	prev := cur
	cur = cur.Next
	for ; cur != nil; cur = cur.Next {
		if cur.Val == prev.Val {
			prev.Next = cur.Next
		} else {
			prev = cur
		}
	}
	return head
}