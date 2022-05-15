/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }
        ListNode *l1 = nullptr;
        ListNode *l2 = nullptr;
        
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *temp = nullptr;
        int i = 1;
        while(cur != nullptr) {
            if( i == left ) {
                l1 = cur;
                l2 = prev;
            } else if (i > left && i < right) {
                temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
                i++;
                continue;
            } else if(i == right) {
                l1->next = cur->next;
                cur->next = prev;
                if(l2 != nullptr) {
                    l2 -> next = cur;
                } else {
                    return cur;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
            ++i;
        }
        return head;
    }
};