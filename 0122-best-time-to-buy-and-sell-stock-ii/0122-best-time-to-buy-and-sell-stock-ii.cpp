class Solution {
public:

    int solve(vector<int>& prices,vector<vector<int>>& dp, int i, bool buy){
        if(i == prices.size() - 1){
            if(buy){
                dp[i][1] = 0;
                return 0;
            }
            else{
                dp[i][0] = prices[i];    
                return prices[i];
            }
        }
        int profit,a,b; 
        if(dp[i+1][0] != -1) a = dp[i+1][0];
        else a = solve(prices,dp,i+1,false);
        if(dp[i+1][1] != -1) b = dp[i+1][1];
        else b = solve(prices,dp,i+1,true);

        if(buy){
            profit = max(-prices[i] + a,0 + b); 
            dp[i][1] = profit; 
            return profit;
        }
        else{
            profit = max(prices[i] + b,0  + a);
            dp[i][0] = profit;
            return profit;
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,dp,0,1);
    }
};