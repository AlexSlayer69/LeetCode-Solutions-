class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n+1,true);
        dp[0] = false;
        dp[1] = false;
        int count = 0;
        for(int i = 2;i<n;i++){
            if(dp[i]){
                count++;
                for(int j = 2*i;j<=n;j+=i) dp[j] = false;
            }
        }
        return count;
    }
};