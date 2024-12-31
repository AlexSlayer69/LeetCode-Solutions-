class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n, vector<int>(m + 1));
        vector<vector<int>> v(26);
        for (int i = 0; i < ring.size(); i++) {
            v[ring[i] - 'a'].push_back(i);
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int res = INT_MAX;
                if (ring[i] == key[j]) {
                    res = min(res, 1 + dp[i][j + 1]);
                } else {
                    auto it = upper_bound(v[key[j] - 'a'].begin(), v[key[j] - 'a'].end(), i);
                    int prevIdx, nextIdx;
                    if (it != v[key[j] - 'a'].end()) {
                        nextIdx = *it;
                    } else {
                        nextIdx = v[key[j] - 'a'][0];
                    }
                    if (it != v[key[j] - 'a'].begin()) {
                        prevIdx = *(it - 1);
                    } else {
                        prevIdx = v[key[j] - 'a'][v[key[j] - 'a'].size() - 1];
                    }

                    res = min(res, 1 + (prevIdx < i ? i - prevIdx : (n - prevIdx + i)) + dp[prevIdx][j + 1]);
                    res = min(res, 1 + (nextIdx > i ? nextIdx - i : (n - i + nextIdx)) + dp[nextIdx][j + 1]);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
};