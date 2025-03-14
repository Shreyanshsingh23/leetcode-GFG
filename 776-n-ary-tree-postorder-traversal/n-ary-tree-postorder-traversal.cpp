/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    void f(Node* root)
    {
        if(root == NULL)return;


        auto v = root->children;
        for(auto& e: v)
        {
            f(e);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        f(root);
        return ans;
    }
};