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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        auto cur1 = list1, cur2 = list2;
        
        while(cur1 and cur2){
            if(cur1->val < cur2->val){
                tail->next = cur1;
                tail = cur1;
                cur1 = cur1->next;
            }
            else{
                tail->next = cur2;
                tail = cur2;
                cur2 = cur2->next;
            }
        }

        while(cur1){
            tail->next = cur1;
            tail = cur1;
            cur1 = cur1->next;
        }

        while(cur2){
            tail->next = cur2;
            tail = cur2;
            cur2 = cur2->next;
        }

        tail->next = NULL;
        return dummy->next;
    }
};