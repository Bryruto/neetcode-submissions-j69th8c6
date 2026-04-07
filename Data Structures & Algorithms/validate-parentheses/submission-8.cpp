#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> open;
        std::unordered_map<char,char> close = {{')','('},{'}','{'},{']','['}};
        
        for(char c:s){
            if((c == ']')||(c == '}')||(c == ')')){
                if(open.empty()) return false;
                if(open.top() != close[c]) return false;
                open.pop();
            }
            else open.push(c);
        } 
        return (open.empty())? true:false;
    }
};
