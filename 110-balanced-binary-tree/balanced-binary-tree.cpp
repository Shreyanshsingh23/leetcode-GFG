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

    map<TreeNode*,int> mp;

    int f(TreeNode* root)
    {
        if(root == NULL)return 0;

        int ans = 0;
        ans = max(ans,1 + f(root->left));
        ans = max(ans,1 + f(root->right));

        return mp[root]  = ans;
    }

public:
 int i = 0;
    bool isBalanced(TreeNode* root) {
        if(i == 0){
            int ok = f(root);
        }
        i++;
        if(root == NULL)return true;

        int leftHeight = mp[root->left];
        int rightHeight = mp[root->right];

        if(abs(leftHeight - rightHeight) > 1)return false;
        int ans = true;
        ans &= isBalanced(root->left);
        ans &= isBalanced(root->right);

        return ans;
        

    }
};