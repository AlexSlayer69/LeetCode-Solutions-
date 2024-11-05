class Solution {
public: 

    int solve(int i,bool bound,int mask,vector<vector<vector<int>>> &dp,string &s){
        if(i == s.length()) return (mask != 0) ? 1 : 0;

        if(dp[i][bound ? true : false][mask] != -1)
            return dp[i][bound ? true : false][mask];

        int maxd = 9;
        if(bound) maxd = s[i] - '0';
        int ans = 0;
        for(int j = 0;j <= maxd;j++){
            if((mask & (1 << j)) != 0) continue;
            int newMask = (mask == 0 && j == 0) ? mask : (mask | (1 << j));
            ans += solve(i+1,bound && (j == s[i] - '0') , newMask,dp,s);
        }
        return dp[i][bound ? true : false][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        vector<vector<vector<int>>> dp(s.length(),vector<vector<int>>(2,vector<int>(1024,-1)));
        int unique = solve(0,true,0,dp,s);
        return n - unique;
    }
};