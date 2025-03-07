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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head, fast = head, dummy = new ListNode(-1);
        auto tail = dummy;
        for(int i = 0; i < n; ++i){
            fast = fast->next;
        }
        
        while(fast){
            tail->next = slow;
            tail = slow;
            fast = fast->next;
            slow = slow->next;
            
        }
        slow = slow->next;
        while(slow){
            tail->next = slow;
            tail = slow;
            slow = slow->next;
        }
        tail->next = NULL;
        return dummy->next;
    }
};