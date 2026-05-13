class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> result(temp);

        for(int i{};i<temp.size();i++){
            int tmp = i + 1;

            bool found = false;
            while(!found && tmp < temp.size()){
                if(temp[tmp] > temp[i]) 
                    found = true; 
                tmp++; 
            }

            result[i] = found ? tmp-i-1 : 0;

        }
        return result;
    }
};
