class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> days;
        for(int i{};i<temperatures.size();i++){
            
            bool app = false; 
            
            for(int j = i + 1;j<temperatures.size();j++){
                if(temperatures[i] < temperatures[j]){
                    days.push_back(j-i);
                    app = true;
                    break;
                }
            }

            if(!app) days.push_back(0);     
        }
        
        return days;
    }
};
