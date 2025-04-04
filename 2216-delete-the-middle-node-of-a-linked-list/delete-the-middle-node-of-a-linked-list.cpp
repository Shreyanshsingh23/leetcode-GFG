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
    ListNode* deleteMiddle(ListNode* head) {
        auto slow = head, fast = head->next;
        if(fast == NULL)return NULL;
        int cnt = 0;
        auto prev = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(cnt > 0)prev = prev->next;
            cnt++;
        }
        if(fast){
            slow->next = slow->next->next;
        }
        else{
            prev->next = prev->next->next;
        }
        cout << cnt << '\n';
        return head;
    }
};