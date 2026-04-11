class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(size_t i{};i<numbers.size();i++){
            for(size_t j = i + 1;j < numbers.size();j++){
                if(numbers[i] + numbers[j] == target) return {i+1,j+1};
            }
        }
    }
};
