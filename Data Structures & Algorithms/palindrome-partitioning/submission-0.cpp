class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> tmp;
        dfs(0,s,tmp,result);
        return result;
    }

    void dfs(int i,string& s,vector<string>& tmp,vector<vector<string>>& result){
        if(i >= s.length()){
            result.push_back(tmp);
            return;
        }        

        for(int j = i;j<s.size();j++){
            if(is(s,i,j)){
                tmp.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,tmp,result);
                tmp.pop_back();
            }
        }
    }

    bool is(string& s,int l,int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
