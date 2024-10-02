class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> vis(n,-1);
        vis[0] = 0;
        for(int j = 0;j<graph[0].size();j++) vis[graph[0][j]] = 1;             
        
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                vis[i] = 0;
                for(int j = 0;j<graph[i].size();j++){
                    if(vis[graph[i][j]] == 0) {
                        vis[i] = 1;
                        break;
                    }
                    if(vis[graph[i][j]] == 1) {
                        vis[i] = 0;
                        break;
                    }
                }
            }
            if(vis[i] == 0){
                for(int j = 0;j<graph[i].size();j++){
                    if(vis[graph[i][j]] == 0) return false;
                    if(vis[graph[i][j]] == -1) vis[graph[i][j]] = 1;
                }
            }
            if(vis[i] == 1){
                for(int j = 0;j<graph[i].size();j++){
                   if(vis[graph[i][j]] == 1) return false;
                   if(vis[graph[i][j]] == -1) vis[graph[i][j]] = 0;
                }
            }
        }
        return true;
    }
};