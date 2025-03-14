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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        while(!q.empty()){
            int n = q.size();
            vector<int>res;
            for(int i = 0; i < n; ++i){
                auto cur = q.front();
                q.pop();
                res.push_back(cur->val);

                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};