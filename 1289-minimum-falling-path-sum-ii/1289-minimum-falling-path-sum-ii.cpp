class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
    
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }
        

        for (int i = 1; i < n; ++i) {
         
            int min1 = INT_MAX, min2 = INT_MAX;
            int minIdx = -1;
            for (int j = 0; j < n; ++j) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                    minIdx = j;
                } else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }
            

            for (int j = 0; j < n; ++j) {
                if (j != minIdx) {
                    dp[i][j] = min1 + grid[i][j];
                } else {
                    dp[i][j] = min2 + grid[i][j];
                }
            }
        }
        

        int minSum = INT_MAX;
        for (int j = 0; j < n; ++j) {
            minSum = min(minSum, dp[n - 1][j]);
        }
        
        return minSum;
    }
};