class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        int mod = 1e9 + 7;
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                dp[i][word[i] - 'a']++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >= 0; j--) {
                dp[j+1] += (int)((long)dp[j] * dp[i][target[j] - 'a'] % mod);
                dp[j+1] %= mod;
            }
        }
        
        return dp[m];
    }
};