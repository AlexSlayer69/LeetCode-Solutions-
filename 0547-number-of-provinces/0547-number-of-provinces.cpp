class Solution {
public:

    void dfs(int n, vector<vector<int>> &adj, vector<bool> &vis){
        vis[n] = true;
        for(int i = 0;i < adj.size();i++){
            if(adj[n][i] && !vis[i]) dfs(i,adj,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n,false);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};