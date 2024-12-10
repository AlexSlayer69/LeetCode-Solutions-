struct VectorHash {
    size_t operator()(const std::vector<int>& vec) const {
        size_t hash = 0;
        for (int i : vec) {
            hash ^= std::hash<int>()(i);
        }
        return hash;
    }
};

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        int ans = 0;
        std::unordered_map<std::vector<int>, int, VectorHash> mp;

        for (auto& it : dominoes) {
            std::sort(it.begin(), it.end());
            ans += mp[it];
            mp[it]++;
        }

        return ans;
    }
};