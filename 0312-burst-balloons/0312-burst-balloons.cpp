class Solution {
public:

    int helper(int s,int e,vector <int> &nums, vector<vector<int>> &dp){
        if (s > e) return 0;
        if (dp[s][e]!=-1) return dp[s][e];
        int maxi=INT_MIN;
        for(int i=s;i<=e;i++){
            int temp=nums[i]*nums[s-1]*nums[e+1];
            temp+=helper(s,i-1,nums,dp)+helper(i+1,e,nums,dp);
            maxi=max(maxi,temp);
        }
        dp[s][e]= maxi;
        return dp[s][e];
    }

    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1);
        for(int i=0;i<nums.size();i++) v.push_back(nums[i]);
        v.push_back(1);
        vector<vector<int>> dp(v.size(),vector<int> (v.size(),-1));
        return helper(1,v.size()-2,v,dp);
    }
};