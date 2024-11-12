class Solution {
public:
    int kInversePairs(int n, int k) {
        if(k > (n*(n-1))/2) return 0;
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(k + 2,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            long long t = 0;
            for(int j = 0;j <= k;j++){
                t += dp[i-1][j];
                if(j >= i) t -= dp[i-1][j-i];
                dp[i][j] = t%mod;
            }
        }
        return dp[n][k];
    }
};