class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty())return 0;
        
        int best{1};
        std::set<int> s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end());

        for(int i{},count{1};i<nums.size()-1;i++){
            if(nums[i] + 1 != nums[i+1]){
                if(best < count) best = count;
                count = 0;
            }
            count++;
            if(i == nums.size() - 2) 
                if(best < count) best = count;
        }
        return best; 
    }
};

