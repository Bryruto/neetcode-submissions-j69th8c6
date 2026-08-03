class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> tmp;
        look(0,target,result,tmp,nums);
        return result;
    }

    void look(int index,int target,std::vector<std::vector<int>>& result,std::vector<int>& tmp,std::vector<int>& nums){


        if(0 == target){
            result.push_back(tmp);
            return;
        } 
        
        if(index > nums.size() - 1 ||0 > target)
            return;

        tmp.push_back(nums[index]);
        look(index + 1,target - nums[index],result,tmp,nums);
        tmp.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index+1])
            index++;
        look(index + 1,target,result,tmp,nums); 
    }

};
