class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0 || n == 1 || k == 0) return false;
        int i =0,j = 1;
        for(j = 1;j < n;j++){
            if(j - i == k){
                while(i != j){
                    if(nums[i] == nums[j]) return true;
                    i++;
                }
            }
            else if(nums[i] == nums[j]) return true;
        }
        return false;
    }
};