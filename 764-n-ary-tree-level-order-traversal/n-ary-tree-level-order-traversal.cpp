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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            vector<int> res;
            for(int i = 0; i < n; ++i){
                auto cur = q.front();
                q.pop();
                res.push_back(cur->val);
                auto v = cur->children;
                for(auto& e : v){
                    q.push(e);
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};