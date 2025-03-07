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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = new ListNode(-1);
        auto  cur = head, tail = dummy;

        int i = 0;
        for(int i = 0; i < left-1; ++i){
            tail->next = cur;
            tail = cur;
            cur = cur->next;
        }
        auto dummy2 = new ListNode(-1);
        auto t2 = dummy2;

        auto nxt = head;
        for(int i = 0; i < right-left+1;++i){
            // cout <<"cur:" <<  cur->val << " t2: " << t2->val << '\n';
            t2->next = cur;
            t2 = t2->next;
            cur = cur->next;
        }

        nxt = cur;
        t2->next = NULL;
        dummy2 = reverseList(dummy2->next);
        tail ->next = dummy2;
        while(tail and tail->next){
            cout << tail->val << ' ';
            tail = tail->next;
        }
        tail ->next = nxt;

        return dummy->next;
    }
};