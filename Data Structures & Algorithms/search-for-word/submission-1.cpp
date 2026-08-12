class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r{};r<board.size();r++){
            for(int c{};c<board[r].size();c++){
                set<pair<int,int>> path;
                if(dfs(0,r,c,word,board,path))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int i, int r, int c,string& word ,vector<vector<char>>& board, set<pair<int,int>>& path){
        if(i == word.length())
            return true;

        if(r<0 || c<0 || r >= board.size() || c >= board[0].size() || path.find({r,c}) != path.end() || board[r][c] != word[i])
            return false;

        path.insert({r,c});
        bool truth = dfs(i + 1,r + 1,c,word,board,path) || 
                     dfs(i + 1,r - 1,c,word,board,path) ||
                     dfs(i + 1,r,c + 1,word,board,path) ||
                     dfs(i + 1,r,c - 1,word,board,path);
        path.erase({r, c});
        return truth;  
    }
};
