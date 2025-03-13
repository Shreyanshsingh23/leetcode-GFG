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
    int ans = 0;

    void dfs(TreeNode* root, int cur){
        if(root == NULL)return;

        cur = cur*2 + root->val;
        if(!root->left and !root->right)
        ans += cur;

        dfs(root->left,cur);
        dfs(root->right,cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};