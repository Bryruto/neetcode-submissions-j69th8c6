class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return look(0,nums);
    }

    vector<vector<int>> look(int index,vector<int>& nums){
        if(index == nums.size())
            return {{}};

        vector<vector<int>> res;
        vector<vector<int>> perm = look(index + 1,nums);

        for(auto vec : perm){
            for(int i{};i<vec.size() + 1;i++){
                vector<int> copy(vec);
                copy.insert(copy.begin() + i,nums[index]);
                res.push_back(copy);
            }
        }

        return res;
    } 
};
