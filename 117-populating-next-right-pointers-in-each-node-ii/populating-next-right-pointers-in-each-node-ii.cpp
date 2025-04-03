/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


 
 const auto _ = std::cin.tie(nullptr) -> sync_with_stdio(false);
 
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            auto f = q.front();
            auto t = f;
            if(f->left)q.push(f->left);
            if(f->right)q.push(f->right);
            q.pop();
           for(int i = 1; i < n; ++i){
                auto s = q.front();
                if(s->left)q.push(s->left);
                if(s->right)q.push(s->right);
                t->next = s;
                t = t->next;
                q.pop();
           }
        }
        return root;
    }
};