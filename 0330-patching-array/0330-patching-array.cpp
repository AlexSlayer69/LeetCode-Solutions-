class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long temp = 1;
        int i = 0;
        int ans = 0;

        while (temp <= n) {
            if (i < nums.size() && nums[i] <= temp) {
                temp += nums[i++];
            } 
            else {
                temp *= 2;
                ans++;
            }
        }

        return ans;
    }
};