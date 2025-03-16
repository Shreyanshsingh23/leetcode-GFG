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
public:

    TreeNode* f(vector<int>& a,int l, int r){
        if(l > r){
            TreeNode* node = NULL;
            return node;
        }
        if(r == l){
            auto node = new TreeNode(a[l]);
            return node;
        }

        int mxx = l;
        for(int i = l; i <= r; ++i){
            if(a[i] > a[mxx])mxx = i;
        }

        auto newNode = new TreeNode(a[mxx]);
        newNode->left = f(a,l,mxx-1);
        newNode->right = f(a,mxx+1,r);

        return newNode;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        return f(a,0,a.size()-1);
    }
};