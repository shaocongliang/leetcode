/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getListLength(head *ListNode) int {
	node := head
	length := 0

	for ; node != nil; node = node.Next {
		length++
	}
	return length
}

func getPivotNode(head *ListNode, pos int) (*ListNode, *ListNode, *ListNode) {
	node := head
	var prev *ListNode
	var last *ListNode
	var pivot *ListNode

	n := 0
	for node.Next != nil {
		if n == pos-1 {
			prev = node
		}
		node = node.Next
		n++
		if n == pos {
			pivot = node
		}
	}
	last = node
	return prev, pivot, last
}

func rotateRight(head *ListNode, k int) *ListNode {
	length := getListLength(head)
	if length == 0 || length == 1 || k == 0 || k%length == 0 {
		return head
	}

	n := k % length
	prev, pivot, last := getPivotNode(head, length-n)

	last.Next = head
	prev.Next = nil
	return pivot
}