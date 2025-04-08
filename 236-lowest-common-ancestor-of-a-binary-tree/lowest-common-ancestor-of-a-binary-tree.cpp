/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    pair<bool,bool> f(TreeNode* root, TreeNode* p, TreeNode* q, bool& a, bool& b)
    {
        if(!root)return {0,0};
        // if(root->val == 3){
        //     cout << a << ' ' << b << '\n';
        // }
        auto x = f(root->left,p,q,a,b), 
        y = f(root->right,p,q,a,b);
        if(x.first and y.second and !ans){
            ans = root;
            return x;
        }
        x.first |= y.first;
        x.second |= y.second;
        if(root == p)x.first = true;
        if(root == q)x.second = true;
        if(x.first and x.second and !ans)ans = root;
        return x;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       bool a = false, b = false;
         f(root,p,q,a,b);
         return ans;
    }
};