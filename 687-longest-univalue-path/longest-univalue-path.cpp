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
 #define pi pair<int,int>
class Solution {
public:
    int ans = 0;
    pi f(TreeNode* a)
    {
        if(!a){
            return {0,-1e9};
        }
        pi l = f(a->left);
        pi r = f(a->right);
        int v = a->val;
        if(l.second == r.second and l.second == v){
            ans = max(ans,l.first+r.first);
            return {max(l.first,r.first)+1,v};
        }
        else if(v == l.second){
            ans = max(ans,l.first);
            return {l.first+1,v};
        }
        else if(v == r.second){
            ans = max(ans,r.first);
            return {r.first+1,v};
        }
        return {1,v};
    }

    int longestUnivaluePath(TreeNode* root) {
        f(root);
        return ans;
    }
};