class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> mp(n+1,vector<int>());
        vector<int> t(n+1,0);
        for(auto it : trust){
            t[it[0]]++;
            mp[it[1]].push_back(it[0]);
        }
        for(int i = 1;i<=n;i++){
            if(t[i] == 0 && mp[i].size() == n-1){
                cout << i << endl;
                return i;
            }
        }
        return -1;
    }
};