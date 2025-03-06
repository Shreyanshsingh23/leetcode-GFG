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
        
    auto rev = reverseList(head);
    // return rev;

    auto dummy = new ListNode(-1);
    auto tail = dummy;
    int largestTillNow = -1;
    while(rev != NULL and rev->val > 0){
        if(rev->val >= largestTillNow){
            largestTillNow = rev->val;
            tail->next = rev;
            tail = rev;
        }
        rev = rev->next;
    }

    tail->next = NULL;
    auto ans = reverseList(dummy->next);
    return ans;
    }
};