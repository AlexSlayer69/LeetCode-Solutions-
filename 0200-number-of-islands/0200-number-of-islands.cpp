class Solution {
public:

    int traverse(pair<int,int>pos,vector<vector<bool>> &vis,int l,int k,vector<vector<char>>& grid){
        if(vis[pos.first][pos.second] == true) return 0;
        else{
            queue<pair<int,int>> q;
            q.push({pos.first,pos.second});
            while(!q.empty()){
                int n = q.size();
                for(int i = 0;i < n;i++){
                    pair<int,int> top = q.front();
                    q.pop();
                    vis[top.first][top.second] = true;
                    if(top.first != l-1){
                        if(!vis[top.first+1][top.second] && grid[top.first+1][top.second]=='1')
                            q.push({top.first+1,top.second});  
                    }
                    if(top.second != k-1){
                        if(!vis[top.first][top.second+1]&&grid[top.first][top.second+1]=='1')
                            q.push({top.first,top.second+1}); 
                    }
                    if(top.first != 0){
                        if(!vis[top.first-1][top.second] && grid[top.first-1][top.second]=='1')
                            q.push({top.first-1,top.second});
                    }
                    if(top.second != 0){
                        if(!vis[top.first][top.second-1]&&grid[top.first][top.second-1]=='1')
                            q.push({top.first,top.second-1}); 
                    }
                }
            }
        }
    return 1;
    }    

    int numIslands(vector<vector<char>>& grid) {
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,false));
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1')
                    c += traverse({i,j},vis,n,m,grid);
            }
        }
        return c;
    }
};