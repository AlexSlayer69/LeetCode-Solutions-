class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 0;
        int pre = 1;
        unordered_map<char, int> maps;
        maps[p[0]] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - p[i - 1]== 1 || p[i] - p[i - 1] == -25) {
                pre += 1;
            } else {
                pre = 1;
            }
            maps[p[i]] = max(pre, maps[p[i]]);
        }
        for (auto [k, v] : maps) {
            ans += v;
        }
        return ans;
    }
};