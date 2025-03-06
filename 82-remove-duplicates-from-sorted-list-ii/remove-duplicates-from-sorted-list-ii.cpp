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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> st;
        auto dummy = new ListNode(-1);
        auto tail = dummy;
        auto cur = head;
        ListNode *nxt = NULL;
        if(cur)nxt = cur -> next;

        while(cur and nxt){
            if(cur->val != nxt->val and st.count(cur->val) == 0){
                tail->next = cur;
                tail = cur;
            }
            st.insert(cur->val);
            cur = nxt;
            nxt = cur->next;
        }


        if(cur != NULL){
            cout <<"cur.val: " <<  cur->val << endl;
            for(auto e: st)cout << e << ' ';

            if(st.count(cur->val) == 0){
                tail->next = cur;
                tail=tail->next;
                // cur = cur->next;
            }
        }
        tail->next = NULL;

        return dummy->next;
    }
};