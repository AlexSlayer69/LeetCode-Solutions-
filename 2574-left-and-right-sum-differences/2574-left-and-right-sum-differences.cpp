class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int n = nums.size();
        int right = 0;

        for (int i = 0; i < n; i++)
            right += nums[i];

        int left = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            right -= nums[i];
            res.push_back(abs(left - right));
            left += nums[i];
        }

        return res;
    }
};