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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p == NULL and q == NULL)return true;
       if(p and q == NULL)return false;
       if(p == NULL and q)return false;

       if(p->val != q->val)return false;

       bool leftAns = isSameTree(p->left,q->left);
       if(leftAns == false)return false;
       
       bool rightAns = isSameTree(p->right,q->right);
       if(rightAns == false)return false;

       return true;
    }
};