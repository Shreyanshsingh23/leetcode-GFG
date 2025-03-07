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

    void reorderList(ListNode* head) {
        auto slow = head, fast = head->next;
        auto dummy = new ListNode(-1);
        auto tail = dummy, cur = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        auto head2 = slow->next;
        slow->next = NULL;
        head2 = reverseList(head2);

        cur = head;
        auto cur2 = head2;
        int i = 0;
        while(cur and cur2){
            if(i&1){
                tail->next = cur2;
                tail = cur2;
                cur2 = cur2->next;
            }
            else{
                tail->next = cur;
                tail = cur;
                cur = cur->next;
            }
            i++;
        }
        while(cur){
            tail->next = cur;
            tail = cur;
            cur = cur->next;
        }

        while(cur2){
            tail->next = cur2;
            tail = cur2;
            cur2 = cur2->next;
        }
        

        tail ->next = NULL;


    }

};