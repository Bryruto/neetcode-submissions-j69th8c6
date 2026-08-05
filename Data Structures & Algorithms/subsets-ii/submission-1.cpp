class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> result;
       vector<int> sub;
       dfs(0,sub,nums,result);
       return result; 
    }

    void dfs(int index,vector<int>& sub,vector<int>& nums,vector<vector<int>>& result){
        if(index >= nums.size()){
            result.push_back(sub);
            return; 
        }

        sub.push_back(nums[index]);
        dfs(index+1,sub,nums,result);
        sub.pop_back();

        while(index + 1 < nums.size() && nums[index] == nums[index+1])
            index++;
        dfs(index + 1,sub,nums,result);
    }
};
