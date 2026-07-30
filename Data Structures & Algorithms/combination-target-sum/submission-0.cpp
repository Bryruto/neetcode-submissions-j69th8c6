class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> tmp;
        toOrNotTo(0,target,result,tmp,nums);
        return result; 
    }

    void toOrNotTo(int index,int target,std::vector<std::vector<int>>& result,std::vector<int>& tmp,std::vector<int>& nums){
        int sum{};
        for(auto& i:tmp) sum+=i;
        if(sum == target){
            result.push_back(tmp);
            return;
        }
        else if(sum > target || index > (int)nums.size() - 1) return;
        
        tmp.push_back(nums[index]);
        toOrNotTo(index,target,result,tmp,nums);
        tmp.pop_back();
        toOrNotTo(index + 1,target,result,tmp,nums);
    }
};
