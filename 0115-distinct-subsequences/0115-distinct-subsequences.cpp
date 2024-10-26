class Solution {
public:

    int solve(int a, int b, string s, string t, vector<vector<int>> &dp){
        if(dp[a][b] != -1) return dp[a][b];
        int n = s.length(),m = t.length();
        if(n < m) return 0;
        if(m == 0) return (n == 0) ? 0 : 1;
        if(n == 1 && m == 1) return (s[0] == t[0]) ? 1 : 0;
        if(s[0] != t[0]){
            dp[a+1][b] = solve(a+1,b,s.substr(1,n-1),t,dp);
            dp[a][b] = dp[a+1][b];
            return dp[a][b];
        }
        else{
            dp[a][b] = solve(a+1,b,s.substr(1,n-1),t,dp) + 
                       solve(a+1,b+1,s.substr(1,n-1),t.substr(1,m-1),dp);
            return dp[a][b];           
        }
    }

    int numDistinct(string s, string t) {
        // dp[a][b] is no. of distinct subseq of s[a,..] which == t[b,---]
        // what are rules
        // if s[0] != t[0] dp[a+1][b]
        // else   
        // we can take or not take 
        // takes dp[a][b] = dp[a+1][b+1] + not takes dp[a+1][b]
        int n = s.length(),m = t.length();
        if(n < m) return 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        return solve(0,0,s,t,dp);
    }
};