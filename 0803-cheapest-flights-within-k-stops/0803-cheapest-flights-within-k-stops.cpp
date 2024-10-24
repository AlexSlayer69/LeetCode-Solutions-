class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto a : flights) adj[a[0]].push_back({a[2],a[1]});
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto [p, el] = pq.top();
            pq.pop();
            if(el.first == dst) return p;
            if(el.second > k) continue;
            for(auto it : adj[el.first]){
                    if(dist[it.second][el.second+1] > p + it.first){
                        dist[it.second][el.second+1] = p + it.first;
                        pq.push({dist[it.second][el.second+1],{it.second,el.second+1}});
                    }
                }  
            } 
        return -1; 
    }
};