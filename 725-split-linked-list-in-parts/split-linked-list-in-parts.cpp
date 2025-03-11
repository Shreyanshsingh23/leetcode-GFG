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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head == NULL){
            vector<ListNode*> ans;
            for(int i = 0; i < k; ++i){
                ans.push_back(NULL);
            }
            return ans;
        }

        vector<ListNode*> ans;
        int len = 1;
        auto cur = head;
        while(cur->next){
            cur = cur->next;
            ++len;
        }
        cout << "len: " <<len << '\n';
        int size = len/k;
        int rem = len%k;

        cur = head;
        bool empty = false;
        for(int num = 0; num < k; ++num){
            int groupSize = empty? 0:size;
            if(rem > 0){
                cout << rem << '\n';
                groupSize+= 1;
                rem--;
            }
            if(groupSize == 0){
                ans.push_back(NULL);
                continue;
            }
            auto dummy = cur;
            for(int i = 0; i < groupSize-1; ++i){
                if(cur->next == NULL){
                    empty = true;
                }
                else cur = cur->next;
            }
            if(cur){
                auto nxt = cur->next;
                cur->next = NULL;
                cur = nxt;
            }

            ans.push_back(dummy);
        }

        return ans;
    }
};