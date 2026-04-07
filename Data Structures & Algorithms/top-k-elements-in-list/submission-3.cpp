/*
make a hash map data structure that have counts
make int key that is max 
loop through the data in array 
    if element is not in counst hash map add it 
    else element count + 1
    check if we have a new max
return max*/
#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(int i{};i<nums.size();i++){
            counts[nums[i]]++;//i think i can do this because hashmaps have 0 at every index you call
        }
        vector<int> result;
        while(k){
            int max{};
            int maxValue{};


            for(auto& v:counts){
                if(v.second > maxValue){
                    max = v.first;
                    maxValue = v.second;
                }
            }
            

            result.push_back(max);
            counts.erase(max);
            k--;
        }

        return result;
    }
};
