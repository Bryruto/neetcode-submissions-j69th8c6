#include <map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int,int> hashmap;
        for(int i:nums){
            if(hashmap[i] != 0)return true;
            hashmap[i] = 1;
        }
        return false;
}};