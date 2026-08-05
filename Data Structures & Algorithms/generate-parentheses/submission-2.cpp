class Solution {
public:
    vector<string> ans;
    string curr{};

    void generate(int n, int open) {
        if(n == 0 && open == 0) {
            ans.push_back(curr);
            return;
        }

        if(n > 0){
            curr.push_back('(');
            generate(n - 1, open + 1);
            curr.pop_back();
        }

        if(open > 0) {
            curr.push_back(')');
            generate(n, open-1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n, 0);
        return ans;
    }
};
