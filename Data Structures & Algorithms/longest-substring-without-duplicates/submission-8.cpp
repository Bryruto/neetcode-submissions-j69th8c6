class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int max{0},curr{};

        for(int k{};k<s.size();k++){
            unordered_map<char,int> mapp;
        
            for(int i = k;i<s.size();i++){
            
                if(mapp.find(s[i]) != mapp.end()) break; 

                mapp[s[i]] = 1;
        
            }
            max = max < mapp.size() ? mapp.size() : max; 
        }
        
        return max;
    }
};
