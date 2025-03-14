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
public:
    vector<int> a;
    void dfs(TreeNode* root)
    {
        if(root == NULL)return;

        a.push_back(root->val);
        
        dfs(root->left);
        dfs(root->right);
    }

    void f(TreeNode* root)
    {
        if(root == NULL)return;

        root->val = mp[root->val];
        
        f(root->left);
        f(root->right);
    }

    map<int,int> mp;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)return root;

        dfs(root);

        sort(a.begin(),a.end());
        mp[a[a.size()-1]] = a[a.size()-1];
        for(int i = a.size()-2; i >= 0; --i){
            int val = a[i];
            a[i] += a[i+1];
            mp[val] = a[i];
        }

        f(root);
        
        return root;

    }
};