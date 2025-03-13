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

    int dp[110];

    void bfs(TreeNode* root, int x, int y){
        if(root == NULL)return;
        queue<TreeNode*> q;

        q.push(root);
        dp[root->val] = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int dis = dp[cur->val];
            if(cur->left and cur->right){
                if((cur->left->val == x and y == cur->right->val ) or (cur->left->val == y and x== cur->right->val )){
                    continue;
                }
            }
            if(cur->left){
                dp[cur->left->val] = dis+1;
                q.push(cur->left);
            }

            if(cur->right){
                dp[cur->right->val] = dis+1;
                q.push(cur->right);
            }
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        memset(dp,-1,sizeof(dp));
        bfs(root,x,y);

        return (dp[x] != -1 and dp[x] == dp[y]);
    }
};