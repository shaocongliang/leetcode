ListNode *advance(ListNode *node, int distance) {
  for (; distance > 0 && node != nullptr; distance--) {
    node = node->next;
  }
  return node;
}

class Solution {
 public:
  ListNode *sortList(ListNode *node) {
    int len = getLengthOfList(node);
    int i = 1;
    ListNode *prev = node;
    ListNode *cur = nullptr;
    ListNode *head = nullptr;
    for (; i < len; i = i * 2) {
      int num;
      if (len % (2 * i) == 0) {
        num = len / (2 * i);
      } else {
        num = len / (2 * i) + 1;
      }
      for (int j = 0; j < num; ++j) {
        ListNode *l1 = prev;
        ListNode *r1 = advance(prev, i);
        ListNode *l2 = r1;
        ListNode *r2 = advance(r1, i);

        if (!head) {
          if (l2 != nullptr) {
            if (l1->val < l2->val) {
              head = l1;
              l1 = l1->next;
            } else {
              head = l2;
              l2 = l2->next;
            }
            cur = head;
          }
        }
        while (l1 != r1 || l2 != r2) {
          if (l1 != r1 && l2 != r2) {
            if (l1->val < l2->val) {
              cur->next = l1;
              l1 = l1->next;
            } else {
              cur->next = l2;
              l2 = l2->next;
            }
          } else if (l1 == r1) {
            cur->next = l2;
            l2 = l2->next;
          } else {
            cur->next = l1;
            l1 = l1->next;
          }
          cur = cur->next;
        }
        prev = r2;
      }
      cur->next = nullptr;
      prev = head;
      head = nullptr;
    }
    return prev;
  }
  int getLengthOfList(ListNode *head) {
    int i = 0;
    while (head != nullptr) {
      i++;
      head = head->next;
    }
    return i;
  }
};