class Solution {
public:
    int dp[21][21]; 
    
    int optimalPlay(vector<int>& nums, int l, int r) {
        if (l > r) return 0;
        
        if (dp[l][r] != -1) return dp[l][r];  
        int pickLeft = nums[l] - optimalPlay(nums, l + 1, r);  
        int pickRight = nums[r] - optimalPlay(nums, l, r - 1); 
        
        dp[l][r] = max(pickLeft, pickRight);  
        return dp[l][r];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp)); 
    
        return optimalPlay(nums, 0, n - 1) >= 0;
    }
};
