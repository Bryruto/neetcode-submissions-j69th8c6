class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int less = nums[0];
        for(const int& i:nums){
            if(i < less)
                less = i;
        }
        return less;
    }
};
