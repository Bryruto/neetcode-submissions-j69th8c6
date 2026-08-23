class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; 

        //make the board
        vector<string> board;
        for(int i{};i<n;i++){
            string tmp; 
            for(int j{};j<n;j++){
                tmp.push_back('.');
            }
            board.push_back(tmp);
        }

        set<int> pos;
        set<int> neg;
        set<int> col;

        backtrack(n,0,pos,neg,col,result,board);
        return result;
    }

    void backtrack(int size, int r, set<int>& pos, set<int>& neg , set<int>& col,
                    vector<vector<string>>& result, vector<string>& board){
        
        if(r >= size){
            result.push_back(board);
            return;
        }

        for(int c{};c<size;c++){
            if(board[r][c] == 'Q' || pos.find(r+c) != pos.end() || neg.find(r-c) != neg.end() || col.find(c) != col.end())
                continue;
            else{
                pos.insert(r+c);
                neg.insert(r-c);
                col.insert(c);
                board[r][c] = 'Q';

                backtrack(size,r + 1,pos,neg,col,result,board);

                pos.erase(r+c);
                neg.erase(r-c);
                col.erase(c);
                board[r][c] = '.';
            }
        }
        return;
    }
};
