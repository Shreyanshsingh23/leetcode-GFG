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
int ans = -1e9;
int f(TreeNode* a)
{
    if(!a)return 0;
    int left = f(a->left);
    int right = f(a->right);
    int v = a->val;
    ans = max({ans,left+v,right+v,left+right+v,v});
    return max({left,right,0})+v;
}
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};