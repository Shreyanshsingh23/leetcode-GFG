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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-101);
        auto tail = dummy;
        auto cur = head;
        while(cur){
            if(cur->val != tail->val){
                tail->next = cur;
                tail = cur;
            }
            cur = cur->next;
        }
        tail->next = NULL;

        return head = dummy->next;
    }
};