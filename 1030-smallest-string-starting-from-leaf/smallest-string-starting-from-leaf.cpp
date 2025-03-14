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
    string minn;
    void dfs(TreeNode* root, string cur)
    {
        if(root == NULL)return;
        cur =  (char)(root->val + 'a') + cur;
        if(root->left == NULL and root->right == NULL)
        {
            if(minn == "" or cur < minn){
                minn = cur;
            }
        }

        if(root->left){
            dfs(root->left,cur);
        }
        if(root->right){
            dfs(root->right,cur);
        }
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return minn;
    }
};