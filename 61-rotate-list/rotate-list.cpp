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
    ListNode* lastKth(ListNode* head, int k){
        auto slow = head, fast = head;
        for(int i = 0; i < k; ++i){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }

    int getLen(ListNode* head){
        int len = 0;
        auto cur = head;
        while(cur){
            ++len;
            cur = cur->next;
        }

        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = getLen(head);
        if(len == 0)return NULL;
        k %= len;
        if(k == 0)return head;
        auto lastNode = lastKth(head,k+1);
        auto head2 = lastNode->next;
        auto cur2 = head2;
        lastNode->next = NULL;
        while(cur2->next){
            cur2 = cur2->next;
        }
        cur2->next = head;
        head = head2;
        return head;
    }
};