class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto it : prerequisites) adj[it[1]].push_back(it[0]);

        int n = queries.size();
        vector<bool> ans(n,false);
        
        for(int i = 0;i < n;i++){
            vector<bool> vis(n,false);
            queue<int> q;
            q.push(queries[i][1]);

            while(!q.empty()){
                int l = q.front();
                vis[l] = true;
                q.pop();
                int flag = false;
                for(auto k : adj[l]){
                    if(k == queries[i][0]){
                        ans[i] = true;
                        flag = true;
                        break;
                    }
                    if(!vis[k]) q.push(k);
                }
                if(flag) break;
            }
        }
        return ans;
    }
};