class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int r = -1;
        for(int i =0;i<nums.size();i++){
            if((nums[i]%2) == 0){
                r++;
                swap(nums[r],nums[i]);
            }
        }
        return nums;
    }
};