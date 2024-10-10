class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
                            ,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist (n, vector<int> (m,INT_MAX));
        dist[0][0] = 0;
        vector<pair<int,int>> dir = {{0,-1},{-1,0},{1,0},{0,1}};
        while(!pq.empty()){
            auto [dt,el] = pq.top();
            int row = el.first;
            int col = el.second;
            pq.pop();
            for(int i = 0;i < 4;i++){
                int nx = row + dir[i].first;
                int ny = col + dir[i].second;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int newdist = max(dt,abs(heights[nx][ny] - heights[row][col]));
                    if(dist[nx][ny] > newdist){
                        dist[nx][ny] = newdist;
                        pq.push({newdist,{nx,ny}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};