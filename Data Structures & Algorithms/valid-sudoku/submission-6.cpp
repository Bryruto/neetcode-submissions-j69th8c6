class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        unordered_map<int,vector<char>> column;
        unordered_map<int,vector<char>> table;

        //check the row
        for(int i{};i<board.size();i++){
            unordered_map<char,int> check_row;
            for(int j{};j<board[i].size();j++){
                if(board[i][j] == '.') continue;
                if(check_row[board[i][j]] != 0) return false;
                check_row[board[i][j]] = 1;


                column[j].push_back(board[i][j]);
                

                if(i < 3 && j < 3) table[0].push_back(board[i][j]);

                else if(i < 3 && j < 6) table[1].push_back(board[i][j]);
                else if(i < 3 && j < 9) table[2].push_back(board[i][j]);

            
                else if(i < 6 && j < 3) table[3].push_back(board[i][j]);
                else if(i < 6 && j < 6) table[4].push_back(board[i][j]);
                else if(i < 6 && j < 9) table[5].push_back(board[i][j]);


                else if(i < 9 && j < 3) table[6].push_back(board[i][j]);
                else if(i < 9 && j < 6) table[7].push_back(board[i][j]);
                else if(i < 9 && j < 9) table[8].push_back(board[i][j]);
                
            }
        }

        //check the column 
        for(auto elements: column){
            unordered_map<char,int> check_column;
            for(char c:elements.second){
                if(check_column[c] != 0) return false;
                check_column[c] = 1;
            }
        }


        for(auto items: table){
            unordered_map<char,int> check_3x3;
            for(char c:items.second){
                if(check_3x3[c] != 0) return false;
                check_3x3[c] = 1;
            }
        }

        return true;
    }
};
