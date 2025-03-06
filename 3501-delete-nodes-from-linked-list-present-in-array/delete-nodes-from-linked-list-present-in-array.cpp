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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st {nums.begin(), nums.end()};
        auto dummy = new ListNode(-1);
        auto tail = dummy;

        auto cur = head;
        while(cur != NULL){
            if(!st.count(cur -> val)){
                tail -> next = cur;
                tail = cur;

            }
            cur = cur -> next;
        }
        tail -> next = NULL;

        return dummy->next;

    }
};