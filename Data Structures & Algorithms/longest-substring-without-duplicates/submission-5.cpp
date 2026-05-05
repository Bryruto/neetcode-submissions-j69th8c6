class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max{};
        
        for(size_t i{};i<s.size();i++){
            std::string hold;

            for(size_t j=i;j<s.size();j++){
                if(hold.find(s[j]) != std::string::npos) break;
                hold += s[j];
            }
            
            if(hold.size() > max)
                max = hold.size(); 
        }

        return max;
    }
};
