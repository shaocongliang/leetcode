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
    void reorderList(ListNode* head) {
      vector<ListNode*> vec;
      vec.resize(5*10*10*10*10);
      ListNode *cur = head;
      
      int num = 0;
      while(cur != nullptr) {
        vec[num++] = cur;
        cur = cur->next;
      }
      
      
      for(int i = 0; i < num/2; ++i) {
        cur = vec[i];
        cur->next = vec[num-i-1];
        cur->next->next = vec[i+1];
      }
      vec[num/2]->next = nullptr;
    }
};
