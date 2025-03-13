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
    bool f(TreeNode* root, int sum)
    {
        if(root == NULL)return false;
        if(root->left == NULL and root->right == NULL and sum-root->val == 0)return true;

        bool ans = false;
        // if(root->val > sum)return false;
        ans |= f(root->left,sum - root->val);
        ans |= f(root->right,sum - root->val);

        return ans;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,targetSum);
    }
};