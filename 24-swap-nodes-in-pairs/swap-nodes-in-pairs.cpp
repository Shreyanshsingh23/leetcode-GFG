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
        auto tail = dummy, cur = head;
        while(cur){
        ListNode *temp = NULL;
            if(cur->next){
                tail->next = cur->next;
                tail = cur->next;
                temp = tail->next;
            }
                tail->next = cur;
                tail = cur;
                cur = temp;
        }
        tail->next = NULL;
        return dummy->next;
    }
};