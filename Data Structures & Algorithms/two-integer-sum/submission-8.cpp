/*
make a hashmap called looking 
iterate over the array
    do target - current element
    if t - c = value we are looking for
        return that value index and current value index 
return false
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> looking; // value->index
        for(int i{},value{};i<nums.size();i++){
            value = target - nums[i];
            if(looking.find(value) != looking.end()) return {looking[value],i};
            looking[nums[i]] = i; 
        }
    }
};
