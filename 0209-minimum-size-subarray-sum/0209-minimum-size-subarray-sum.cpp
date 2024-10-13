class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int mini = INT_MAX;
        int sum = 0;
        int l = 0;
        for(int r =0;r<n;r++){
            sum += nums[r];
            
            while(sum >= target){
                mini = min(mini,r-l+1);
                sum -= nums[l];
                l++;
            }

        }

        if(mini == INT_MAX) return 0;
        
        return mini;
    }
};