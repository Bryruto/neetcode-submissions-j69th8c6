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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str;
        lookthr(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return dfs(s); 
    }

    TreeNode* dfs(stringstream& s){
        string str;
        s >> str;
        if(str == "N") 
            return nullptr;

        TreeNode* node = new TreeNode(stoi(str));
        node->left = dfs(s);
        node->right = dfs(s);

        return node; 
    }

    void lookthr(TreeNode* root,std::string& str){
        if(!root){
            str += "N ";
            return; 
        }

        str += std::to_string(root->val) + " ";
        
        lookthr(root->left,str);
        lookthr(root->right,str); 
    }
};
