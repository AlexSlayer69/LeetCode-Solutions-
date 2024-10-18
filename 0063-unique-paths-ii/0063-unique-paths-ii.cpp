class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        if(grid[m-1][n-1] == 1) return 0;
        dp[m-1][n-1] = 1;
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j >=0;j--){
                if(i == m-1 && j == n-1) continue;
                if(grid[i][j] == 1) dp[i][j] = 0;
                else{
                    long long down,right;
                    if(i < m-1) down = dp[i+1][j];
                    else down = 0;
                    if(j < n-1) right = dp[i][j+1];
                    else right = 0;
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};