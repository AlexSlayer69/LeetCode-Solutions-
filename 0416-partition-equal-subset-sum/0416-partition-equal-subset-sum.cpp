class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int total = 0,n = nums.size();
        for(int i =0;i<n;i++) total += nums[i];
        if((total%2) == 1 || n == 1) return false;
        vector<vector<bool>> dp (n, vector<bool>((total/2) +1,false));
        
        for(int i = 0;i<n;i++)
            dp[i][0] = true;
        for(int j = 1;j<=total/2;j++)
            dp[0][j] = ((j == nums[0]) ? true : false); 

        for(int i = 1;i<n;i++){
            for(int j = 1; j <= total/2;j++){
                if(dp[i-1][j]) dp[i][j] = true; 
                else if(j >= nums[i] && dp[i-1][j-nums[i]]) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }

        return (dp[n-1][total/2]);
    }
};