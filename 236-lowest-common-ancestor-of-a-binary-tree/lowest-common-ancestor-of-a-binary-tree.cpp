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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root == p or root == q)return root;
        auto leftLCA = lowestCommonAncestor(root->left,p,q);
        auto rightLCA = lowestCommonAncestor(root->right,p,q);
        if(leftLCA and rightLCA)return root;
        if(!rightLCA)return leftLCA;
        return rightLCA;
    }
};