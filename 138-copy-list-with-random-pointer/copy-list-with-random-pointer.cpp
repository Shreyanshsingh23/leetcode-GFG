/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        auto dummy = new Node(-1);
        auto tail = dummy;
        auto cur = head;
        while(cur){
            auto newNode = new Node(cur->val);
            tail->next = newNode;
            tail = newNode;
            mp[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        auto cur2 = dummy->next;
        while(cur){
            cur2->random = mp[cur->random];
            cur = cur->next;
            cur2 = cur2->next;
        }

        return dummy->next;
    }
};