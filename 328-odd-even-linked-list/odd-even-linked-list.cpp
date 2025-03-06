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
    ListNode* oddEvenList(ListNode* head) {
        auto d1 = new ListNode(-1);
        auto d2 = new ListNode(-1);
        auto t1 = d1, t2 = d2, cur = head;

        int i = 0;
        while(cur){
            if(i&1){
                t2->next = cur;
                t2 = t2->next;
            }
            else{
                t1->next = cur;
                t1 = t1->next;
            }
            cur = cur->next;
            i++;
        }
        t2->next = NULL;
        t1->next = d2->next;

        return d1->next;
    }
};