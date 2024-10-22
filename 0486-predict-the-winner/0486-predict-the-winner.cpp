class Solution {
public:
    
    int optimalPlay(vector<int>& nums, int l, int r,vector<vector<int>> &dp) {
        if (l > r) return 0;
        
        if (dp[l][r] != -1) return dp[l][r];  
        int pickLeft = nums[l] - optimalPlay(nums, l + 1, r,dp);  
        int pickRight = nums[r] - optimalPlay(nums, l, r - 1,dp); 
        
        dp[l][r] = max(pickLeft, pickRight);  
        return dp[l][r];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(21, vector<int> (21,-1));
        return optimalPlay(nums, 0, n - 1,dp) >= 0;
    }
};
