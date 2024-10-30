class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX_XOR = 1024;
        vector<unordered_map<int, int>> freq(k);
        
        for (int i = 0; i < n; ++i) {
            int pos = i % k;
            freq[pos][nums[i]]++;
        }

        
        vector<vector<int>> dp(k + 1, vector<int>(MAX_XOR, INT_MIN));
        dp[0][0] = 0; 

        for (int i = 1; i <= k; ++i) {
            int maxPrevRow = *max_element(dp[i - 1].begin(), dp[i - 1].end());

            for (int xorValue = 0; xorValue < MAX_XOR; ++xorValue) {
                for (auto& [num, count] : freq[i - 1]) {
                    dp[i][xorValue] = max(dp[i][xorValue], dp[i - 1][xorValue ^ num] + count);
                }
                dp[i][xorValue] = max(dp[i][xorValue], maxPrevRow);
            }
        }

        return n - dp[k][0];
    }
};