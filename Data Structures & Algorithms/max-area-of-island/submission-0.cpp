class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int count{};
        for(int r{};r<grid.size();r++){
            for(int c{};c<grid[0].size();c++){
                if(grid[r][c]==1){
                    count = max(count,dfs(r,c,grid));
                }
            }
        }
        return count;
    }

    int dfs(int r,int c,vector<vector<int>>& grid){
        if(r<0 || c <0 || r >= grid.size() || c >=grid[0].size() || grid[r][c] != 1){
            return 0;
        }
        
        grid[r][c] = 0;
        return 1 + dfs(r+1,c,grid) + dfs(r-1,c,grid) + dfs(r,c-1,grid) + dfs(r,c+1,grid);
    }

};
