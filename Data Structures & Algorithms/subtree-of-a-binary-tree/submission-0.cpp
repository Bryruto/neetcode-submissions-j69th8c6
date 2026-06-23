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
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!sub) return true;
        
        if(!root) return false;

        else if(root->val == sub->val)
            if(check(root,sub)) return true;

        return isSubtree(root->left,sub) || isSubtree(root->right,sub);
    }

    bool check(TreeNode* root,TreeNode* sub){
        if(!root && !sub) return true;
    
        if(!root || !sub || root->val != sub->val) return false;
    
        return check(root->left,sub->left) && check(root->right,sub->right); 
    }
};
