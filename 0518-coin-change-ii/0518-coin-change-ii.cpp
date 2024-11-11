class Solution {
public:

    int solve(int amount,int i,vector<int>& coins, vector<vector<int>> &dp){
        if(amount < 0) return 0;
        if(amount == 0) return 1;
        if(i >= coins.size()) return 0;
        if(dp[amount][i] != -1) return dp[amount][i];
        dp[amount][i] = solve(amount-coins[i],i,coins,dp) + solve(amount,i+1,coins,dp);
        return dp[amount][i];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        return solve(amount,0,coins,dp);
    }
};