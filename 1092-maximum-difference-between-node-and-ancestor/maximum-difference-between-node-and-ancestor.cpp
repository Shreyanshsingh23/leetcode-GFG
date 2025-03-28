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

    int ans = 0;

    void f(TreeNode* root, int mxx, int minn)
    {
        if(!root)return;
        mxx = max(mxx,root->val);
        minn = min(minn,root->val);
        ans = max(ans,mxx-minn);
        cout << mxx-minn << '\n';
        f(root->left,mxx,minn);
        f(root->right,mxx,minn);
    }
    int maxAncestorDiff(TreeNode* root) {
        f(root,root->val,root->val);
        return ans;
    }
};