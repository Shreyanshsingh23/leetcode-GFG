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
     ListNode* reverseList(ListNode* head) {
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

    bool isPalindrome(ListNode* head) {
        auto fast = head->next, slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        auto l2 = slow->next;
        slow->next = NULL;
        auto head2 = reverseList(l2);

        auto cur = head, cur2 = head2;
        while(cur and cur2){
            if(cur->val != cur2->val)return false;
            cur = cur->next;
            cur2 = cur2->next;
        }
        return true;
        


    }
};