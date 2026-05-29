class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(size_t i{};i<nums.size();i++){
            for(size_t j = i + 1;j<nums.size();j++){
                if(nums[i] == nums[j])
                    return nums[i];
            }
        }
    }
};
