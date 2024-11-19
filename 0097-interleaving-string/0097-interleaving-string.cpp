class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>> &dp){
        if(!(i+j)) return true;
        if(dp[i][j] != -1) return false;
        if(i && s1[i-1] == s3[i+j-1] && solve(i-1,j,s1,s2,s3,dp)) 
            return dp[i][j] = true;
        if(j && s2[j-1] == s3[i+j-1]) 
            return dp[i][j] = solve(i,j-1,s1,s2,s3,dp);
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) 
            return false;
        vector<vector<int>> dp(105, vector<int>(105,-1));
        return solve(s1.size(),s2.size(),s1,s2,s3,dp);
    }
};