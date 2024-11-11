class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(2,1));
        dp[n-1][0] = 1; // down
        dp[n-1][1] = 1; // up
        for(int i = n-2;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[i] - nums[j] > 0){
                    dp[i][0] = max(dp[i][0],1+dp[j][1]);
                }
                else if(nums[i] - nums[j] < 0){
                    dp[i][1] = max(dp[i][1],1+dp[j][0]);
                }
            }
        }
        return max(dp[0][0],dp[0][1]);
    }
};