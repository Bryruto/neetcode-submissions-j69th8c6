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
    int best{};
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int left = longest(root->left); 
        int right = longest(root->right);

        best = left + right > best ? left + right : best;

        best = max(best,diameterOfBinaryTree(root->left));
        best = max(best,diameterOfBinaryTree(root->right));

        return best;
    }

    int longest(TreeNode* root){
        if(!root) 
            return 0;

        int left = 1 + longest(root->left);
        int right = 1 + longest(root->right);
        
        return max(left,right); 
    }
};
