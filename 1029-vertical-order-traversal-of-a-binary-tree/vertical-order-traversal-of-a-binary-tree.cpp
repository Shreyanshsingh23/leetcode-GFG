
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
 # define pi pair<int,int>
class Solution {
public:
  
    map<int,vector<pi>> mp;
    void f(TreeNode* root, int col, int row)
    {
        if(!root)return;
        mp[col].push_back({row,root->val});
        f(root->left,col-1,row+1);
        f(root->right,col+1,row+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pi>> a(2010);
        f(root,1000,0);
        vector<vector<int>> ans;
        for(auto& [x,y]: mp)
        {
            vector<int> t;
            sort(y.begin(),y.end());
            for(auto& e: y){
                t.push_back(e.second);
            }
            ans.push_back(t);
        }
        mp.clear();
        return ans;
    }
};
