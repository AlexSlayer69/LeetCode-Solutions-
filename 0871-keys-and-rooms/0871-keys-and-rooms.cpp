class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        stack<int> s;
        vis[0] = true;
        s.push(0);
        while(!s.empty()){
            int k = s.top();
            s.pop();
            for(auto it : rooms[k]){
                if(!vis[it]){
                    vis[it] = true;
                    s.push(it);
                }
            }
        }
        for(auto it : vis){
            if(!it) return false;
        }
        return true;
    }
};