class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        queue<pair<int,int>> q;
        if(grid[0][0] == 1) return -1;
        q.push({0,0});
        vector<int> dx = {-1,0,1};
        vector<int> dy = {-1,0,1};
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [row , col] = q.front();
                vis[row][col] = true;
                if(row == n-1 && col == n-1) return level;
                q.pop();
                for(int i = 0 ; i < 3;i++){
                    int nx = row + dx[i];
                    for(int j = 0;j < 3;j++){
                        int ny = col + dy[j];
                        if(nx >=0 && nx <= n-1 && ny >=0 && ny <= n-1 && 
                        grid[nx][ny] == 0 && !vis[nx][ny]){
                            vis[nx][ny] = true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        level++;
        }
    return -1;
    }
};