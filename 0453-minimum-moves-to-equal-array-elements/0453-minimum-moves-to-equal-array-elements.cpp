class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0];
        int sum = 0;
        for(int num:nums){
            if(num < min){
                min = num;
            }
            sum += num;
        }
        return(sum - min * n);
    }
};