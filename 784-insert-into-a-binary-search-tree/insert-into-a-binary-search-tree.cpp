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
    void f(TreeNode* root, int val)
    {
        if(val < root->val){
            if(!root->left){
                auto nn = new TreeNode(val);
                root->left = nn;
                return;
            }
            f(root->left,val);
        }
        else{
            if(!root->right){
                auto nn = new TreeNode(val);
                root->right = nn;
                return;
            }
            f(root->right,val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        f(root,val);
        return root;
    }
};