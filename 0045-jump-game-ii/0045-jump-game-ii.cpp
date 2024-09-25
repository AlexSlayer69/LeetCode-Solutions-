class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,INT_MAX);
        ans[0] = 0;
        for(int i = 0;i<n;i++){
            for(int j = i;j < n && j <= i+nums[i] ;j++){
                ans[j] = min(ans[i] + 1, ans[j]);
            }
        }
        return ans[n-1];
    }
};