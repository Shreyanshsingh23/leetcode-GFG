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

    int dfs(TreeNode* root)
    {
        if(root == NULL)return 1e7;
        if(root->left == NULL and root->right == NULL)return 1;
        int ans = 1e9;

        ans = min(ans,1+dfs(root->left));
        ans = min(ans,1+dfs(root->right));

        return ans;
    }

    

    int minDepth(TreeNode* root) {
        if(root == NULL)return 0;
        return dfs(root);
    }
};