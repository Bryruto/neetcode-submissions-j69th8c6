#include <set>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<vector<int>> tmp;


        for(size_t i{};i < nums.size();i++){
            for(size_t j = i+1;j < nums.size();j++){
                for(size_t k = j + 1;k < nums.size();k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        std::vector<int> not_num = {nums[i],nums[j],nums[k]};
                        bool flip;
                        do{
                            flip = false;
                            for(int i{},tmp{};i< not_num.size()-1;i++){
                                if(not_num[i] > not_num[i+1]){
                                    tmp = not_num[i];
                                    not_num[i] = not_num[i+1]; 
                                    not_num[i+1] = tmp;
                                    flip = true;
                                }
                            }
                        }while(flip); 
                        tmp.insert(not_num);
                    } 
                }
            }
        }

        std::vector<std::vector<int>> result(tmp.begin(),tmp.end()); 
        return result;
    }
};
