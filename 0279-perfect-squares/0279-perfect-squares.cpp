class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        vector<int> dp(n + 1, 1e5);
        dp[0] = 0;
        for(int i = 0;i*i <= n;i++) sq.push_back(i * i);
        for (int i = 1; i <= n;i++){
            for (int j = 0; j < sq.size();j++){
                if (i - sq[j] >= 0) dp[i] = min(dp[i], dp[i - sq[j]] + 1);
            }
        }
        return dp[n];
    }
};