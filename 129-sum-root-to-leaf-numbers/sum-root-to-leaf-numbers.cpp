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
    long long ans = 0;

    void f(TreeNode* root, int cur)
    {
        if(root == NULL)return;

        if(root->right == NULL and root->left == NULL){
            cur = cur*10 + root->val;
            ans += cur;
            return;
        }

        cur = cur*10 + root->val;
        if(root->left)f(root->left,cur);
        if(root->right)f(root->right,cur);
    }

    int sumNumbers(TreeNode* root) {
        f(root,0);
        return ans;
    }
};