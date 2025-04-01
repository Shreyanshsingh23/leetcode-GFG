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
int ans = 0;
map<int,int> mp;
class Solution {
public:
    void f(TreeNode* a,int cnt)
    {
        if(!a->left and !a->right)
        {   
           mp[a->val]++;
           if(mp[a->val]&1)cnt++;
            else cnt--;
            mp[a->val]--;
            if(cnt < 2)ans++;
            return;
        }

        mp[a->val]++;
        if(mp[a->val]&1)cnt++;
        else cnt--;
        if(a->left)f(a->left,cnt);
        if(a->right)f(a->right,cnt);
        mp[a->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        f(root,0);
        int t = ans;
        ans = 0;
        mp.clear();
        return t;
    }
};