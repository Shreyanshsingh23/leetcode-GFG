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
    int sum = 0;
    void f(TreeNode* root)
    {
        if(root == NULL)return;

         f(root->right);
         int cur = sum;
         sum += root->val;
         root->val += cur;
         f(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        return root;
    }
};