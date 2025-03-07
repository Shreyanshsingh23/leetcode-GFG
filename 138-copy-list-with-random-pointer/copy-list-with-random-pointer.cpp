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
        auto dummy = new Node(-1);
        auto tail = dummy;
        auto cur = head;
        while(cur){
            auto newNode = new Node(cur->val);
            auto nxt = cur->next;
            cur->next = newNode;
            cur = newNode;
            cur->next = nxt;
            cur = nxt;
        }

        cur = head;
        while(cur){
            auto ran = cur->random;
            cur = cur->next;
            if(ran)
            cur->random = ran->next;
            cur = cur->next;
        }

        int i = 0, cnt = 0;
        cur = head;
        auto dummy1 = new Node(-1);
        auto t1 = dummy1;
        while(cur){
            if(i&1){
                tail->next = cur;
                tail = cur;
                cur = cur->next;
            }
            else{
                t1 ->next = cur;
                t1= cur;
                cur = cur->next;
            }
            i++;
        }
        tail->next = NULL;
        t1->next = NULL;
        head = dummy1->next;

        return dummy->next;
    }
};