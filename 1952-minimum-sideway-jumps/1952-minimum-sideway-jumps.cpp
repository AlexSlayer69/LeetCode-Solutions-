class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, INT_MAX));
        dp[0][2] = 0;
        dp[0][1] = 1; 
        dp[0][3] = 1;
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<=3; j++){
                if(obstacles[i] == j) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            for(int j = 1; j<=3; j++){
                if(obstacles[i] == j) continue;
                for(int k = 1; k<=3; k++){
                    if(j != k && dp[i][k]!=INT_MAX) 
                    dp[i][j] = min(dp[i][j], dp[i][k] + 1);
                }
            }
        }
        int result = INT_MAX;
        for(int i = 1; i<=3; i++) result = min(result, dp[n-1][i]);
        return result;
    }
};