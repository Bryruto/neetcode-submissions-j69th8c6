class Solution {
public:
    vector<string> res;
    unordered_map<char,string> digitToChar = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0,"",digits);
        return res;
    }

    void backtrack(int i, string curstr,string& digits){
        if(curstr.size() == digits.size()){
            res.push_back(curstr);
            return;
        }
        
        for(auto c : digitToChar[digits[i]]){
            backtrack(i+1,curstr + c,digits);
        }
    }
};
