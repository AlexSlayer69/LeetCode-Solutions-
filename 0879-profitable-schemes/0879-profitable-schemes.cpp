class Solution {
public:    
    int solve(vector<int>&groups, vector<int>&profit , int i ,int p, int n ,int &minProfit, vector<vector<vector<int>>>&dp){
        int mod = 1e9 + 7;
        if(i == profit.size() || n == 0){
            if(p >= minProfit)
                return 1;
            else return 0;    
        }
        if (dp[i][n][min(p, minProfit)] != -1)
            return dp[i][n][min(p, minProfit)];
            
        long long ntake = solve(groups, profit,i+1,p ,  n , minProfit ,dp);
        long long take = 0;
        
        if(groups[i] <= n)
            take = solve(groups,profit,i+1,profit[i]+p,n-groups[i],minProfit,dp);
         return dp[i][n][min(p, minProfit)] = (take % mod + ntake % mod) % mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(group, profit , 0 , 0 , n, minProfit , dp);
    }
};