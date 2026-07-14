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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder = middle,left,right
        //inorder = left,middle,right        

        //base case for recusive function
        if(preorder.empty() || inorder.empty())
            return nullptr;  

        
        //make curr root node
        TreeNode* root = new TreeNode(preorder[0]);


        //find middle which is find root in inorder array
        int mid{}; 
        for(;mid<inorder.size();mid++)
            if(inorder[mid] == preorder[0]) break;
        

        //make the array for everything on the left and right subtrees
        std::vector<int> preRight(preorder.begin() + mid + 1,preorder.end());
        std::vector<int> preLeft(preorder.begin() + 1 ,preorder.begin() + mid + 1);

        std::vector<int> inRight(inorder.begin() + mid + 1,inorder.end());
        std::vector<int> inLeft(inorder.begin(),inorder.begin() + mid + 1);
        
        
        //make subtrees
        root->left = buildTree(preLeft,inLeft);
        root->right = buildTree(preRight,inRight);

        return root;
    }
};
