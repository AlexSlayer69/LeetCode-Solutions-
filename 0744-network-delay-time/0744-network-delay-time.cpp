class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i =0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        if(adj[k].size() == 0) return -1;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n+1,false);
        vector<int> dist(n+1,INT_MAX);
        vis[0] = true;
        dist[0] = 0;
        pq.push({0,k});
        dist[k] = 0;
        vis[k] = true;
        while(!pq.empty()){
            auto [dt,node] = pq.top();
            pq.pop();

            for(auto [wt,next] : adj[node]){
                vis[next] = true;
                if(dist[next] > dt + wt){
                    dist[next] = dt + wt;
                    pq.push({dist[next],next});
                }
            }
        }

        for(auto it : vis){
            if(!it) return -1;
        }

        int ans = 0;
        for(auto it : dist) ans = max(ans,it);

        return ans;
    }
};