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
vector<vector<int>> ans;

class Solution {
public:
    void f(TreeNode* a, int req, vector<int>& cur)
    {
        if(!a->left and !a->right)
        {
            if(req-(a->val) == 0){
                cur.push_back(a->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        req -= a->val;
        if(a->left)
        {
            cur.push_back(a->val);
            f(a->left,req,cur);
            cur.pop_back();
        }
        if(a->right)
        {
            cur.push_back(a->val);
            f(a->right,req,cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return {};
        }
        vector<int> cur;
        f(root,targetSum,cur);
        auto t = ans;
        ans.clear();
        return t;
    }
};