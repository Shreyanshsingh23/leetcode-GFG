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
    bool isLeafNode(TreeNode* root)
    {
        return(!root->left and !root->right);
    }
TreeNode* getMax(TreeNode* root){
    while(root->right){
        root = root->right;
    }
    return root;
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else {
            if(isLeafNode(root))return NULL;
            if(root->right == NULL)return root->left;
            if(root->left == NULL)return root->right ;   
            //find the maximum of LST or minimum of RST
            else{  
                auto mxx = getMax(root->left);
                auto right = root->right;
                auto left = deleteNode(root->left,mxx->val);
                 root = new TreeNode(mxx->val);
                 root->right = right;
                 root->left = left;
                
            }
        }
            return root;
    }
};