class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>());
        for(int i =0;i < n;i++) dp[i].push_back(nums[i]);
        int ind = n-1,maxi = 1;
        for(int i = n-2;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[j]%nums[i] == 0){
                    if(dp[j].size()+1 > dp[i].size()){
                        dp[i] = dp[j];
                        dp[i].push_back(nums[i]);
                    }
                }
                if(maxi < dp[i].size()){
                    ind = i;
                    maxi = dp[i].size();
                }
            }
        }
        return dp[ind];
    }
};