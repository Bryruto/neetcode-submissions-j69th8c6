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
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> smalls;
        dfs(root,smalls); 
        quick(smalls,0,smalls.size() - 1);
        return smalls[k-1];
    }

    void dfs(TreeNode* root,std::vector<int>& smalls){
        if(!root)
            return;
        smalls.push_back(root->val);
        dfs(root->left,smalls);
        dfs(root->right,smalls);
    }


    //sorting 
    int sort(std::vector<int>& smalls,int left,int right){    
        int pivot = smalls[right];

        int i = left -1;

        for(int j = left;j<right;j++){
            if(smalls[j] <= pivot){
                i++; 
                std::swap(smalls[i] , smalls[j]);
            }
        }

        std::swap(smalls[i+1],smalls[right]); 
        return i + 1;
    }

    void quick(std::vector<int>& smalls,int low, int high){
        if(low<high){
            int pi = sort(smalls,low,high);

            quick(smalls,low,pi-1);
            quick(smalls,pi + 1,high);
        }
    }

};

//maybe a 2 pointer 