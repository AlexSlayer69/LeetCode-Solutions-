class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i = 1;i<n;i++){
            for(int j = 1;j <= i;j++){
                if(nums[i-j] < nums[i])
                    dp[i] = max(1 + dp[i-j],dp[i]);
            }
        }
        int mk = dp[0];
        for(int i =0;i<n;i++){
            mk = max(mk,dp[i]);
        }
        return mk;
    }
};