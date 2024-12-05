class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) 
    {    
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>dir={0,1,0,-1,0};
        
        vector<vector<int>> obstacle(m, vector<int> (n, 0));
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        
        queue<vector<int>> q;

        q.push({0, 0, grid[0][0]}); // {x, y, obstacle count}
        obstacle[0][0] = grid[0][0];
        vis[0][0] = true;
        
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto t = q.front();
                q.pop();
                
                int x = t[0];
                int y = t[1];
                int curr_obstacle = t[2];
                
                if(x == m - 1 && y == n - 1) return steps;
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dir[i];
                    int ny = y + dir[i+1];
                    
                    if(nx >= 0 and nx < m and ny >= 0 and ny < n)
                    {
                        int old_obstacle = obstacle[nx][ny]; 
                        int new_obstacle = curr_obstacle + grid[nx][ny]; 
                        
                        if((vis[nx][ny] == false) and new_obstacle <= k)
                        {
                            q.push({nx, ny, new_obstacle});
                            obstacle[nx][ny] = new_obstacle;
                            vis[nx][ny] = true;
                        } 
                        else if(new_obstacle < old_obstacle and new_obstacle <= k)
                        {
                            q.push({nx, ny, new_obstacle});
                            obstacle[nx][ny] = new_obstacle;
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
            
            steps++;
        }
        return -1;
    }
};