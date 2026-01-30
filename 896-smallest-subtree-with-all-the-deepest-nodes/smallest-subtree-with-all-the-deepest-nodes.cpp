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
    pair<int,TreeNode* > f (TreeNode* root){
        if(!root)return{0,nullptr};

        auto l = f(root->left);
        auto r = f(root->right);

        if(l.first == r.first)return{l.first+1, root};
        if(l.first > r.first)return{l.first+1,l.second};
        return {r.first+1,r.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return f(root).second;
    }
};