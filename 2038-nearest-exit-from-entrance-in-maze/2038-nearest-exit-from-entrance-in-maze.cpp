class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        entrance.push_back(0);
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '1';
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i = q.front()[0];
            int j = q.front()[1];
            int l = q.front()[2];
            q.pop();
            for(int k = 0;k<4;k++){
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                if(nx >= maze.size() || nx < 0 || ny < 0 || ny >= maze[0].size()) 
                    continue;
                if(maze[nx][ny] == '.'){
                    if((nx == 0) || (nx == maze.size()-1) || (ny == 0) 
                        || (ny == maze[0].size()-1)){
                        if(nx != entrance[0] || ny != entrance[1])
                            return l+1;
                    }
                    maze[nx][ny] = '1';
                    q.push({nx,ny,l+1});
                }
            }
        }
        return -1;
    }
};