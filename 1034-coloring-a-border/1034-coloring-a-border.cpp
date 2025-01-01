class Solution {
public:
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    void dfs(int r,int c,int n,int m,vector<vector<int>>& grid){
  
        
        int count = 0;
        grid[r][c] = -grid[r][c];
        
        for(int i=0;i<4;i++){
            int x = r + dr[i];
            int y = c + dc[i];
            
            if(x<0 || x>=n || y<0 || y>=m)
                continue;
            
            if(grid[x][y] == grid[r][c]){
                count += 1;
            }
            
            else if(-grid[x][y] == grid[r][c]){
                count += 1;
                dfs(x,y,n,m,grid);
            }
        }
        
        if(count == 4){
            grid[r][c] = -grid[r][c];
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        dfs(row,col,n,m,grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }

        return grid;
    }
};