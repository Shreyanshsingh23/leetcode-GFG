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

    int calculate(string& s){
        cout << s << ' ';
        // auto s = str;
        // reverse(s.begin(),s.end());
        int ans = 0;
        int p = 0;
        for(auto e : s){
            ans = ans*2 + (e-'0');
            p++;
        }
        cout << ans << '\n';
        return ans;
    }

    int dfs(TreeNode* root, string& s){

        int ans = 0;
        s+= (root->val + '0');
        if(root -> left == NULL and root -> right == NULL){
            int ans = calculate(s);
            s.pop_back();
            return ans;
        }
        if(root->left)ans += dfs(root->left,s);
        if(root->right)ans += dfs(root->right,s);
        s.pop_back();

        return ans;
    }

    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        
        return dfs(root,s);

    }
};