class Solution {
public:
    int characterReplacement(string s, int k) {
        int best{};
        for(int i{};i<s.size();i++){
            int count{1},changes = k;


            for(int j = i+1;j<s.size();j++){
                if(s[i] != s[j]){
                    if(changes == 0)break;
                    else changes--;
                    }
                count++;
            }

            for(int j = i-1;j>=0;j--){
                if(s[i] != s[j]){
                    if(changes == 0) break; 
                    else changes--;
                }
                count++;
            }


            best = count > best ? count : best;
        }
        return best; 
    }
};
