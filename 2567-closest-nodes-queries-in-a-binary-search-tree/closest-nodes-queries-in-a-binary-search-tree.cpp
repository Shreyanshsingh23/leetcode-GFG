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

    void f(TreeNode* root, vector<int>& a)
    {
        a.push_back(root->val);
        if(root->left)f(root->left,a);
        if(root->right)f(root->right,a);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> a;
        vector<vector<int>> res;
        f(root,a);
        sort(a.begin(),a.end());
        for(auto ele: q)
        {
            vector<int> temp;
            int l = 0, r = a.size()-1, mid, ans = -1;
            while(l <= r)
            {
                mid = (l+r) >> 1;
                if(a[mid] <= ele){
                    ans = a[mid];
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            temp.push_back(ans);
            ans = -1;
            auto it = lower_bound(a.begin(),a.end(),ele);
            if(it != a.end())ans = *it;
            temp.push_back(ans);
            res.push_back(temp);
        }
        return res;
    }
};