class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
        dist[0][0] = 0;
        pq.push({grid[0][0],{0,0}});
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty()){
            auto [h,el] = pq.top();
            pq.pop();
            int row = el.first;
            int col = el.second;

            for(int i =0 ;i<4;i++){
                int nx = row + dir[i].first;
                int ny = col + dir[i].second;
                if(nx >= 0 && ny >=0 && nx < n && ny < n){
                    if(dist[nx][ny] > max(grid[nx][ny],h)){
                        dist[nx][ny]  = max(grid[nx][ny],h);
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};