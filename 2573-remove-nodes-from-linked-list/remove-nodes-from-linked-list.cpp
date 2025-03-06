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
    ListNode* reverseList(ListNode* head){
        ListNode *prev = nullptr;
        auto cur = head;
        while(cur != NULL){
            auto nxt =  cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
       return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        auto cur = head;
        int mxx = -1;
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        while(cur){
            if(cur->val >= mxx){
                mxx = cur->val;
                tail->next = cur;
                tail = cur;
            }
            cur = cur->next;
        }
        tail->next = NULL;
        auto ans = reverseList(dummy->next);
        return ans;
    
    }
};