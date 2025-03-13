/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

        void dfs(TreeNode* root, vector<string>& a){
            if(root == NULL){
                a.push_back("NULL");
                return;
            }

            a.push_back(to_string(root->val));
            dfs(root->left,a);
            dfs(root->right,a);
        }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> a, b;
        dfs(p,a);
        dfs(q,b);
        
        while( a.size() and a.back() == "NULL"){
            a.pop_back();
        }

        while(b.size() and b.back() == "NULL"){
            b.pop_back();
        }
        if(a.size() != b.size())return 0;
        for(int i = 0;i < a.size(); ++i){
            if(a[i] != b[i])return 0;
        }
        return 1;
    }
};