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
    map<TreeNode*,int> dp[2];
    int f(TreeNode* root, bool prev)
    {   
        if(!root)return 0;
        if(dp[prev].count(root))return dp[prev][root];
        int& ans = dp[prev][root];
        int ans1 = f(root->left,false) + f(root->right,false);

        int ans2 = 0;
        if(!prev){
            ans2 = (root->val) + f(root->left,true) + f(root->right,true);
        }

        ans = max(ans1,ans2);
        return ans;
    }

    int rob(TreeNode* root) {
        return f(root,false);
    }
};