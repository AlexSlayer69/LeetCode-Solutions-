class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<vector<bool>>>> visited(grid.size(), vector<vector<vector<bool>>>(grid[0].size(), vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size()))));

        // find the coordinates of T, B and S
        pair<int,int> locationBox, locationT, locationP;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 'B'){
                    locationBox = make_pair(i, j);
                }
                else if(grid[i][j] == 'T'){
                    locationT = make_pair(i, j);
                }
                else if(grid[i][j] == 'S'){
                    locationP = make_pair(i, j);
                }
            }
        }

        int pushes = 0;
        queue<vector<int>> q;
        q.push({locationBox.first, locationBox.second, locationP.first, locationP.second});
        visited[locationBox.first][locationBox.second][locationP.first][locationP.second] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto pos = q.front();
                q.pop();

                int bx = pos[0], by = pos[1];
                if(bx == locationT.first && by == locationT.second){
                    return pushes;
                }
                
                int sx = pos[2], sy = pos[3];
                // new box position = (bx + 1, by), new man position = (bx - 1, by)
                // new box position = (bx - 1, by), new man position = (bx + 1, by)
                // new box position = (bx, by + 1), new man position = (bx, by - 1)
                // new box position = (bx, by - 1), new man position = (bx, by + 1)
                if(issafe(bx + 1, by, grid) && issafe(bx - 1, by, grid) && 
                    !visited[bx + 1][by][bx - 1][by] && isReachable(bx - 1, by, sx, sy, bx, by, grid)){
                    visited[bx + 1][by][bx - 1][by] = true;
                    q.push({bx + 1, by, bx - 1, by});
                }
                if(issafe(bx - 1, by, grid) && issafe(bx + 1, by, grid) && 
                    !visited[bx - 1][by][bx + 1][by] && isReachable(bx + 1, by, sx, sy, bx, by, grid)){
                    visited[bx - 1][by][bx + 1][by] = true;
                    q.push({bx - 1, by, bx + 1, by});
                }
                if(issafe(bx, by + 1, grid) && issafe(bx, by - 1, grid) && 
                    !visited[bx][by + 1][bx][by - 1] && isReachable(bx, by - 1, sx, sy, bx, by, grid)){
                    visited[bx][by + 1][bx][by - 1] = true;
                    q.push({bx, by + 1, bx, by - 1});
                }
                if(issafe(bx, by - 1, grid) && issafe(bx, by + 1, grid) && 
                    !visited[bx][by - 1][bx][by + 1] && isReachable(bx, by + 1, sx, sy, bx, by, grid)){
                        //cout<<"hey "<<bx<<" "<<by<<" ";
                    visited[bx][by - 1][bx][by + 1] = true;
                    q.push({bx, by - 1, bx, by + 1});
                }
            }
            pushes++;
        }
        
        return -1;
    }

    bool issafe(int i, int j, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#';
    }

    bool isReachable(int destx, int desty, int srcx, int srcy, int currbx, int currby, vector<vector<char>>& grid){
        queue<vector<int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        q.push({srcx, srcy});
        visited[srcx][srcy] = true;
        while(!q.empty()){
            auto pos = q.front();
            q.pop();
            
            int x = pos[0], y = pos[1];
            if(x == destx && y == desty){
                return true;
            }
            
            // 1st condtion: we cannot walk through the box, so not adding that point to the queue
            // Rest are simple bfs conditions
            if(((x + 1) != currbx || y != currby) && issafe(x + 1, y, grid) && !visited[x + 1][y]){
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }
            if(((x - 1) != currbx || y != currby) && issafe(x - 1, y, grid) && !visited[x - 1][y]){
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            }
            if(((x) != currbx || (y + 1) != currby) && issafe(x, y + 1, grid) && !visited[x][y + 1]){
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
            if((x != currbx || (y - 1) != currby) && issafe(x, y - 1, grid) && !visited[x][y - 1]){
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            }
        }

        return false;
    }
};