class Solution {
public:

    double trav(string start,string end,unordered_map<string,vector<pair<string,double>>> &adj,unordered_map<string,bool> &vis){
        double res = -1.0;
        vis[start] = true;
        if(start == end) return 1.0;

        for(int i = 0;i < adj[start].size();i++){
            if(!vis[adj[start][i].first]){
                double d = trav(adj[start][i].first,end,adj,vis); 
                if(d != -1) 
                    res = adj[start][i].second * d;
            }
        }
        return res;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i = 0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        int q = queries.size();
        vector<double> ans(q,-1);
        for(int i =0;i<q;i++){
            unordered_map<string,bool> vis;
            if(adj.find(queries[i][0]) == adj.end() || adj.find(queries[i][1]) == adj.end())
                ans[i] = -1.0;
            else
                ans[i] = trav(queries[i][0],queries[i][1],adj,vis);
        }
        return ans;
    }
};