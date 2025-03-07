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
        auto slow = head, fast = head;
        int diff = 0;
        if(fast == NULL)return NULL;
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        int f = 0, s = 0;
        while(fast->next){
            fast = fast->next;
            ++f;
            if(f-s >= n){
                tail->next = slow;
                tail = slow;
                slow = slow->next;
                ++s;
            }
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