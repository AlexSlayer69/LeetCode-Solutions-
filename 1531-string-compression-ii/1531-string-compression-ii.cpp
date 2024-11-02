class Solution {
public:

    int solve(int ind, string &s,int k,vector<vector<int>> &dp){
        if(ind+k >= s.length()) return 0;
        int l = k;
        if(dp[ind][l] != -1) return dp[ind][l];
        int del = l ? solve(ind+1,s,l-1,dp) : 100;
        int j = ind+1;
        int c = 1;
        while(j <=s.length()){
            del = min(del,
            solve(j,s,l,dp) + 1 + ((c > 100) ? 3 : (c >= 10) ? 2 : (c > 1) ? 1:0));
            if(s[j] == s[ind]) c++;
            else if(--l < 0) break;
            j++;
        }
        return dp[ind][k] = del;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return solve(0,s,k,dp);
    }
};