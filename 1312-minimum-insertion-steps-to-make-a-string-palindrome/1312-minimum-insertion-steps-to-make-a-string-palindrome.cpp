class Solution {
public:
    int n;

    int insertions(string &s){
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][i] = 0;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[i][i+1]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(dp[i][j]==0) continue;
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
        return dp[0][n-1];
    }

    int minInsertions(string s) {
        n = s.length();
        return insertions(s);
    }
};