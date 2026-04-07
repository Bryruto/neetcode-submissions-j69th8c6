class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> seen;
        for(int i : nums){
            for(int p: seen){
                if (i==p){
                    return true;
                    }
            }
            seen.push_back(i);
        }
        return false;
    }
};