class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans(n,false);
        for(int i =0;i<n;i++){
            unordered_map<int,int> mp;
            string k = s.substr(queries[i][0],queries[i][1] - queries[i][0] + 1);
            for(auto c : k){
                mp[c]++;
            }
            int l = 0;
            for(auto it : mp){
                if(it.second%2) l++;
            }
            if((queries[i][1] - queries[i][0] + 1)%2 && (l-1)/2 <= queries[i][2]) ans[i] = true;
            if((queries[i][1] - queries[i][0] + 1)%2 == 0 && l/2 <= queries[i][2]) ans[i] = true;
        }
        return ans;
    }
};