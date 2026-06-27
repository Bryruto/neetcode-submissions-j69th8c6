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
    std::vector<int> rights;
    
    vector<int> rightSideView(TreeNode* root) {
        rightview(root,0);
        return rights; 
    }

    void rightview(TreeNode* root,int level){
        if(!root) return; 
        if(!(rights.size() > level)) rights.push_back(root->val); 
        rights[level] = max(rights[level],root->val);
        rightview(root->left,level+1);
        rightview(root->right,level+1);
    }
};
