class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < (1 << n);i++){
            int temp = 0;
            for(int j = 0;j < n;j++){
                if(i & (1 << j)) temp ^= nums[j];
            }
            sum += temp;
        }
        return sum;
    }
};