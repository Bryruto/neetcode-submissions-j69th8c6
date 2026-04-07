/*
use a hashmap count times you see each element if the same
then true
*/
#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char,int> count_s;
        std::map<char,int> count_t;
        
        for(char c:s){
            if(count_s[c]== 0) count_s[c] = 1;
            else count_s[c]++;
        }

        for(char c:t){
            if(count_t[c]==0) count_t[c] = 1;
            else count_t[c]+=1;
        }

      return count_s == count_t; 
        
    }
};
