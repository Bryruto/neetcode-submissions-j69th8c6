class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count{};
        for(int r{};r<grid.size();r++){
            for(int c{};c<grid[0].size();c++){
                if(grid[r][c] == '1'){
                    dfs(r,c,grid);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(int r,int c,vector<vector<char>>& grid){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1')
            return;

        grid[r][c] = '2';

        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);
    }

};