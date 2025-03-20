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

    void f(int value, TreeNode* root)
    {
        if(value < root->val ){
            if(root->left)f(value,root->left);
            else{
                auto nn = new TreeNode(value);
                root->left = nn;
                return;
            }
        }
        else{
            if(root->right)f(value,root->right);
            else{
                auto nn = new TreeNode(value);
                root->right = nn;
                return;
            }
        }
    }


    TreeNode* bstFromPreorder(vector<int>& a) {
        auto root = new TreeNode(a[0]);
        for(int i = 1; i < a.size(); ++i){
            f(a[i],root);
        }
        return root;
    }
};