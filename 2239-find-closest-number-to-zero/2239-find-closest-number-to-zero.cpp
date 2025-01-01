class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int closest = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (abs(closest) > abs(nums[i]) ||
                abs(closest) == abs(nums[i]) && nums[i] > closest) {
                closest = nums[i];
            }
        }

        return closest;
    }
};