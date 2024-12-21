class Solution {
public:
    int dp[505][505];
    int func(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size()) return -1e9;
        int &ans = dp[i][j];
        if(ans != -1) return ans;

        ans = nums1[i] * nums2[j];
        ans = max(ans, func(i+1, j+1, nums1, nums2)+(nums1[i] * nums2[j]));
        ans = max(ans, func(i+1, j, nums1, nums2));
        ans = max(ans, func(i, j+1, nums1, nums2));

        return ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        return func(0, 0, nums1, nums2);
    }
};