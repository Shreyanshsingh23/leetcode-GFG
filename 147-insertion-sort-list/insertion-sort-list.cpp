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
    
    ListNode* insert(ListNode* dummy, ListNode* cur){
        auto tail = dummy;
        while(tail->next and tail->next->val < cur->val){
            tail = tail->next;
        }
        cur->next = tail->next;
        tail->next = cur;

        return dummy;

    }

public:
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == NULL)return head;
        auto dummy = new ListNode(-5100);
        auto tail = dummy, cur = head;
        while(cur){
            auto nxt = cur->next;
            dummy = insert(dummy,cur);
            cur = nxt;
        }
        return dummy->next;
    }

};