class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans=0,count=0;

        for(int i = 2;i<n;i++){
            if(nums[i-1] - nums[i-2] == nums[i]-nums[i-1]){
                count++;
                ans += count;
            }
            else count=0;
        }
        
        return ans;
    }
};