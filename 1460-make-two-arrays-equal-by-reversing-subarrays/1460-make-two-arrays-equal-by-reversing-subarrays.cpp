class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001, 0);
        for (int num : target) {
            cnt[num]++;
        }
        for (int num : arr) {
            cnt[num]--;
        }
        for (int i{0}; i <= 1000; ++i) {
            if (cnt[i] != 0)  return false;
        }        
        return true;
    }
};