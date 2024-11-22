class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = 0;
        for (int i = 1; i < nums.size(); i++) {
            best = max(nums[i]-nums[i-1], best);
        }
        return best;
    }
};