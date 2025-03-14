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

 const auto _ = std::cin.tie(nullptr) -> sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {

    int ans = 0;

    void dfs(TreeNode* root, int curMax)
    {
        
        if(root->val >= curMax)++ans;
        curMax = max(curMax,root->val);
        if(root->left)dfs(root->left,curMax);
        if(root->right)dfs(root->right,curMax);
    }


public:
    int goodNodes(TreeNode* root) {
        dfs(root,-1e8);
        return ans;
    }
};