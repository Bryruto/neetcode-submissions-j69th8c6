class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        std::unordered_map<int,int> counts;

        for(int& i:nums){
            if(counts[i] >= 1) return i;
            counts[i]++;
        } 
    }
};
