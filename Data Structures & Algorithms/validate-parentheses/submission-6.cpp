#include <stack>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> open;
        //add to open with push back compare 
        for(char c:s){
            if(c == ')'){
                if(open.empty()) return false;
                if(open.top() == '(') open.pop();
                else return false;
            } 
            else if(c == ']'){
                if(open.empty()) return false;
                if(open.top() == '[')open.pop();
                else return false;
            }
            else if(c == '}'){
                if(open.empty()) return false;
                if(open.top() == '{')open.pop();
                else return false;
            }
            else open.push(c);
        } 
        return (open.empty())? true:false;
    }
};
