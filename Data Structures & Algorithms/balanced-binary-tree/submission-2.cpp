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
    int checkHeights(TreeNode* root){
        if(!root) return 0;
        
        int left = checkHeights(root->left); 
        int right = checkHeights(root->right);

        return 1 + max(left,right);
    }

    bool isBalanced(TreeNode* root){
        if(!root) return true;

        int left = checkHeights(root->left);
        int right = checkHeights(root->right);

        if(abs(left-right)>1)return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
