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
        if(root == NULL)return 0;

        int ans = 0;

        ans = max(ans,1+dfs(root->left));
        ans = max(ans,1+dfs(root->right));

        return ans;
    }

    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};