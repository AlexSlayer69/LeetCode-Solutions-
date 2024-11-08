class Solution {
public:

    void dfs(int i,vector<int> temp,vector<int> &vis,vector<vector<int>>& ans,
             vector<vector<int>>& graph,int &n){
        vis[i] = true;
        if(i == n-1){
            temp.push_back(i);
            ans.push_back(temp);
            vis[i] = false;
            return;
        }

        for(auto it : graph[i]){
            if(!vis[it]) {
                temp.push_back(i);
                dfs(it,temp,vis,ans,graph,n);
                temp.pop_back();
            }
        }

        vis[i] = false;
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> vis(n,0);
        dfs(0,vector<int>(),vis,ans,graph,n);
        return ans;
    }
};