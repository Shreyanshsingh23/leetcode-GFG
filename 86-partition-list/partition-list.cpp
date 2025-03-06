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
    ListNode* partition(ListNode* head, int x) {
        auto dummy1 = new ListNode(-1), dummy2 = new ListNode(-1);
        auto tail1 = dummy1, tail2 = dummy2;

        auto cur = head;
        while(cur != NULL){
            if(cur->val < x){
                tail1->next = cur;
                tail1 = cur;
                cur = cur->next;
            }
            else{
                tail2 -> next = cur;
                tail2 = cur;
                cur = cur->next;
            }
        }
        tail2 -> next = NULL;
        tail1 -> next = dummy2 -> next;

        return dummy1->next;
    }
};