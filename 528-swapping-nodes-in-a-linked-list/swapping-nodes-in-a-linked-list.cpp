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

    ListNode* kthNode(ListNode*head, int k){
        auto cur = head;
        for(int i = 0; i < k-1; ++i){
            cur = cur->next;
        }
        return cur;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto right = head, left = head;
        for(int i = 1; i < k; ++i){
            right = right->next;
        }
        auto temp = right;
        while(right->next){
            right = right->next;
            left = left->next;
        }

        swap(temp->val,left->val);
        return head;
       
    }
};