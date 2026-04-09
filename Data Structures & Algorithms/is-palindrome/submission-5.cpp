class Solution {
public:
    bool isPalindrome(string tmp){
        
        std::string s{};
        for(char c:tmp){
            if(c == '!' || c == '?' || c == '.' || c == ' ' || c == '\'' || c== ','|| c == ':') continue;      
            s += (c >= 'A' && c <= 'Z')?c + 32:c;
            }
        


        for(size_t i{};i< static_cast <int>(s.size()/2);i++)
            if(s[i] != s[s.size()- i - 1]) return false;
        
        return true;
    }
};
