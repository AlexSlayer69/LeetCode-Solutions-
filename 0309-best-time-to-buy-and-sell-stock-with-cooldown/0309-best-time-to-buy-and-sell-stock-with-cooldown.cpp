class Solution {
private:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp, int n) {
        if (idx >= n)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];    
        if (buy == 1) 
            return dp[idx][buy] = max (-prices[idx] + solve(idx+1, 0, prices, dp, n), 
                                       0 + solve(idx+1, 1, prices, dp, n));
        return dp[idx][buy] = max (prices[idx] + solve(idx+2, 1, prices, dp, n), 
                                   0 + solve(idx+1, 0, prices, dp, n));
    }    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp, n);
    }
};