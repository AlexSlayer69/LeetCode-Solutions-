class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans(n,false);
        vector< vector<int> > pf;
        vector<int> temp(26,0);
        pf.push_back(temp);
        for(int i =0;i < s.length();i++){
            temp[s[i] - 'a']++;
            pf.push_back(temp);
        }
        for(int i =0;i<n;i++){
            int l = 0;
            for(int j =0;j<26;j++){
                l += (pf[queries[i][1] + 1][j] - pf[queries[i][0]][j])%2;
            }
            if((queries[i][1] - queries[i][0] + 1)%2 && (l-1)/2 <= queries[i][2]) ans[i] = true;
            if((queries[i][1] - queries[i][0] + 1)%2 == 0 && l/2 <= queries[i][2]) ans[i] = true;
        }
        return ans;
    }
};