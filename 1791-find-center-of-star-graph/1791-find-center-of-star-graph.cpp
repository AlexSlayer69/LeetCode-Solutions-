class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> adj;
        int maxi = 0;
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]]++;
            adj[edges[i][1]]++;
            maxi = max(maxi,edges[i][0]);
            maxi = max(maxi,edges[i][1]); 
        }
        for(auto it : adj){
            if(it.second == maxi-1) return it.first;
        }
        return 0;
    }
};