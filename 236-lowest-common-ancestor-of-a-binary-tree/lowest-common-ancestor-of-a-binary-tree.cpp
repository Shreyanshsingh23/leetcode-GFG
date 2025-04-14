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
        if(!root)return NULL;


        auto lca = lowestCommonAncestor(root->left,p,q);
        auto rca = lowestCommonAncestor(root->right,p,q);
        if(root == p or root == q)return root;
        if(lca and rca)return root;
        
        return (lca)? lca: rca;
    }
};