class Solution {
public:
    
    int solve(long n,unordered_map<long, long> &dp){
        if(dp.find(n) != dp.end()) return dp[n];
        if(n == 1) return 0;
        if(!(n%2)) return dp[n] = 1 + solve(n/2,dp);
        return dp[n] = min(1 + solve(n-1,dp), 1+solve(n+1,dp));
    }
public:
    int integerReplacement(int n) {
        unordered_map<long, long> dp;
        return solve(n,dp);
    }
};