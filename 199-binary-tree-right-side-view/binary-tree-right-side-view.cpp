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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        
        vector<int> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
           for(int i = 0; i < n; ++i){
                auto s = q.front();
                if(i == 0){
                    ans.push_back(s->val);
                }
                if(s->right)q.push(s->right);
                if(s->left)q.push(s->left);
                q.pop();
           }
        }
        return ans;
    }
};