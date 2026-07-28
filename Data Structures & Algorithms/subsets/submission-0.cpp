class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums,subset,result,0);
        return result;
    }

    void dfs(vector<int>& nums,vector<int>& subset,vector<vector<int>>& result,int index){
        if(index >= nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums,subset,result,index + 1);
        subset.pop_back();
        dfs(nums,subset,result,index + 1);
    }
};
