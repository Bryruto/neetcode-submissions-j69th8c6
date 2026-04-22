#include <map>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::map<int,int> counts;

        for(auto& i:nums)
            counts[i]+= 1;
        
        int j{0};
        for(const auto& [key,value] : counts)
            for(size_t i{0};i < value;i++)
                nums[j++] = key; 
        
    }
};