class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result{};
        for(std::string& str:strs){
            result+=std::to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i{0};
        std::vector<string> result;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            
            result.push_back(s.substr(j+1,len));
            i = j+len+1;
      }
      return result;
    }
};
