class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result; //this is the result

        for(size_t i{};i<=nums.size()-k;i++){//this is a loop that will go to k less then max of nums size 
            std::vector<int> sub(nums.begin()+i,nums.begin()+i+k); // sub of k size from nums
            int max = sub[0];  // set base max of sub
            for(int& num:sub){//find the max of sub
                if(num > max) max = num;
            }
            result.push_back(max);//push max of sub to result
        }

        return result; 
    }
};
