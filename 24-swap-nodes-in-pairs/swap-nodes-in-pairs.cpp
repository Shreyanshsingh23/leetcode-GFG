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
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        auto cur = head;
        if(!cur or !cur->next){
            return head;
        }
        while(cur and cur->next){
            auto nxt = cur->next->next;
            tail->next = cur->next;
            tail = tail->next;
            tail->next = cur;
            tail = tail->next;
            cur = nxt;
        }
        if(cur){
            tail->next = cur;
            tail = tail->next;
        }

        tail->next = NULL;
        return dummy->next;
    }
};