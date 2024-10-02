class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> gp(n,-1);         
        for(int i = 0;i<n;i++){
            if(gp[i] != -1) continue;
            else{
                gp[i] = 0;
                queue<int> q;
                vector<bool> vis(n,false);
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int l = q.size();
                    int m = q.front();
                    vis[m] = true;
                    q.pop();
                    for(int j = 0;j<graph[m].size();j++){
                        if(gp[graph[m][j]] == gp[m]) return false;
                        if(gp[graph[m][j]] == -1) gp[graph[m][j]] = 1-gp[m];
                        if(!vis[graph[m][j]]) q.push(graph[m][j]);
                    }
                }
            }
        }
        return true;
    }
};