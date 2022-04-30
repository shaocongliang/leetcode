class Solution {
public:
    int selectNode(vector<ListNode*> &lists) {
        int min = 2000000;
        int index = -1;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                int val = lists[i]->val;
                if(val<min) {
                    min = val;
                    index = i;
                }
            }
        }
        return index;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *tail = nullptr;
        ListNode *head = nullptr;
        while(!lists.empty()) {
            int index = selectNode(lists);
            if(index == -1) {
                return head;
            }
            ListNode *t = new ListNode(lists[index]->val);
            if(!head) {
                tail = t;
                head = t;
            } else {
                tail->next = t;
                tail = tail->next;
            }
            lists[index] = lists[index]->next;
            if(lists[index] == nullptr) {
                lists.erase(lists.begin() + index);
            }
        }
        return head;
    }
private:
    std::set<int> unfinishedListNo;
};