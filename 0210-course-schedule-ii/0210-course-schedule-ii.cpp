class Solution {
public:
        bool isCyclic(int i, int n, vector<int> adj[], vector<bool> &vis, vector<bool> &temp, vector<int> &ans){
            vis[i]=true;
            temp[i]=true;
            for(int u:adj[i]){
                if(temp[u])
                    return true;
                else if (!vis[u])
                    if(isCyclic(u,n,adj,vis,temp,ans))
                        return true;
            }
            temp[i]=false;
            ans.push_back(i);
            return false;
        }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        vector<bool> vis(numCourses,false);
        vector<bool> temp(numCourses,false);
        bool flag =true;
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
                if(isCyclic(i,numCourses,adj,vis,temp,ans)){
                    flag = false;
                    break;
                }        
        }
        reverse(ans.begin(),ans.end());
        if(flag) return ans;
        ans.clear();
        return ans;
    }
};