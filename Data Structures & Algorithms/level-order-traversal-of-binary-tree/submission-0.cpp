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
    vector<vector<int>> levels;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        dfs(root,0);

        return levels;
    }

    void dfs(TreeNode* root, int level){
        //check if the level has a vector already
        //we need to make a new vector if it does not exist

        if(!(levels.size() > level)){
            levels.push_back({}); 
        }
        levels[level].push_back(root->val); 
        
        if(root->left) dfs(root->left,level + 1);
        if(root->right) dfs(root->right,level + 1);

    }
};
