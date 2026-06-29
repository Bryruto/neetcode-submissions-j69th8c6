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
    int count{};
    int goodNodes(TreeNode* root) {
        if(!root) return 0; 
        countgood(root,root->val);
        return count;
    }
    void countgood(TreeNode* root,int num){
        if(!root) return;
        if(num <= root->val){
            count++;
            num = root->val; 
        }

        countgood(root->left,num);
        countgood(root->right,num); 
    }
};
