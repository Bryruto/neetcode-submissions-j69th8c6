class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        //int n = nums.size();
        vector<int> result;
        for(int i{};i < nums.size();i++){
            int tmp{1};
            for(int j{};j< nums.size();j++){
                if(j == i) continue; 
                tmp *= nums[j];
            }
            result.push_back(tmp);
        }
        return result;
    }
};
