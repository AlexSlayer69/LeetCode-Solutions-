class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it : connections){
            mp[it[0]].push_back({it[1],0});
            mp[it[1]].push_back({it[0],1});
        }
        int c = 0;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int el = q.front();
            q.pop();
            for(auto it : mp[el]){
                if(!vis[it.first]){
                    vis[it.first] = true;
                    q.push(it.first);
                    if(it.second == 0) c++;
                }
            }
        }
        return c;
    }
};