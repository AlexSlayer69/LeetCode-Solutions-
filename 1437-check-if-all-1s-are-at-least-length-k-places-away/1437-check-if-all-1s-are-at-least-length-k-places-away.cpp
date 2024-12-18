class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int count = k;

        for (int num : nums) {
            if (num == 1 && count < k) return false;
            else if (num == 1) count = 0;
            else count++;
        }

        return true;
    }
};