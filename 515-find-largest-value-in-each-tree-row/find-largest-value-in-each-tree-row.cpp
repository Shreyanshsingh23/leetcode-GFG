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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            long long mxx = -1e18;
            for(int i = 0; i < n; ++i){
                auto cur = q.front();
                q.pop();
                mxx = max((long long)cur->val,mxx);

                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            ans.push_back(mxx);
        }

        return ans;
    }
};