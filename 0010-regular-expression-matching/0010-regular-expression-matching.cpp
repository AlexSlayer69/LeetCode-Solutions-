class Solution {
public:

    bool solve(int i , int j , string s , string p, vector<vector<int>> &dp){
        int n = s.length(), m = p.length();
        if(j == m) return (i == n);
        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(i < n && (p[j] == s[i] || p[j] == '.')) flag = true;
 
        if(j+1 < p.length() && p[j+1] == '*'){
            bool not_take = solve(i, j+2 , s, p ,dp);
            bool take = flag && solve(i+1 , j , s, p, dp);
            dp[i][j] = not_take || take;
            return dp[i][j];
        }

        dp[i][j] = flag && solve(i+1,j+1 , s ,p, dp);
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(21, vector<int> (21,-1));
        return solve(0,0,s,p,dp);
    }
};