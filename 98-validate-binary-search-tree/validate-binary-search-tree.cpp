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
    bool f(TreeNode* root, long long l, long long r)
    {
        if(!root)return true;
        long long v = root->val;
        if(v < l)return false;
        if(v > r)return false;
        return f(root->left,l,v-1) and f(root->right,v+1,r);
    }

    bool isValidBST(TreeNode* root) {
       return f(root, LONG_MIN, LONG_MAX);
    }
};