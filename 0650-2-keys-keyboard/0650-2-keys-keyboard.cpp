class Solution {
public:
    int minSteps(int n) {
        if(n == 0 || n == 1) return 0 ; 
        vector<int> dp(n+1); 
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3 ; i <= n; i++){
            dp[i] = i;
            int j = i/2;
            while(j >= 1){
                if(i % j == 0){
                    dp[i] = min(dp[i] , dp[j] + (i / j));
                }
                j--;
            }
        }
        return dp[n];
    }
};