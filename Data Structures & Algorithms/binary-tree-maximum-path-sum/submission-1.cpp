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
    int maxPathSum(TreeNode* root) {
        int best = root->val;
        dfs(root,best);
        return best;
    }

    int dfs(TreeNode* root,int& best){
        if(!root) return 0;

        int leftmax = max(dfs(root->left,best),0); 
        int rightmax = max(dfs(root->right,best),0);

        best = max(best,root->val + leftmax + rightmax);

        return root->val + max(leftmax,rightmax);
    }
};
