class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int, char> m1;        
        for (int i = 0; i < 9; ++i) {
            char dig = '1' +i;
            m1[cost[i]] = max(m1[cost[i]], dig);
        }
        string zero = "0";
        vector<string> dp(target+1, zero);

        for (auto& [k, v]: m1) {
            if (k <= target) {
                dp[k] = string(1, v);
            }
        }

        for (int i = 1; i <= target; ++i) {
            for (auto& [k, v]: m1) {
                int i1 = i - k;
                if (i1 == 0 && dp[i].size() < 2) {
                    string s1(1, v);
                    dp[i] = max(dp[i], s1);
                } else if (i1 < 0 || dp[i1] == zero) {
                    continue;
                } else if (dp[i].size() <= dp[i1].size()) {
                    dp[i] = dp[i1];
                    dp[i].push_back(v);
                } else if (dp[i].size() == dp[i1].size() + 1) {
                    string s1 = dp[i1];
                    s1.push_back(v);
                    if (s1 > dp[i]) {
                        dp[i] = s1;
                    }
                }
            }
        }
        return dp[target];
    }
};