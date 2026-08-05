class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string tmp;
        dfs(n,0,result,tmp);
        return result;
    }

    void dfs(int n,int open,vector<string>& result,string& tmp){
        if(n == 0 && open == 0){
            result.push_back(tmp);
            return;
        }

        if(n && open){
            tmp+="(";
            dfs(n-1,open+1,result,tmp);
            tmp.pop_back(); 

            tmp+=")";
            dfs(n,open-1,result,tmp);
            tmp.pop_back();
        }
        else if(n){
            tmp+="(";
            dfs(n-1,open+1,result,tmp);
            tmp.pop_back();
        }
        else{
            tmp+=")";
            dfs(n,open-1,result,tmp);
            tmp.pop_back();
        }

    }
};
