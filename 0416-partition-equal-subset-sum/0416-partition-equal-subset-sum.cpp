class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int total = 0,n = nums.size();
        for(int i =0;i<n;i++) total += nums[i];
        if((total%2) == 1 || n == 1) return false;
        vector<bool> prev((total/2) +1,false) , curr((total/2) +1,false);
        
        prev[0] = true,curr[0] = true;
        if(nums[0] <= total/2) prev[nums[0]] = true;

        for(int i = 1;i<n;i++){
            for(int j = 1; j <= total/2;j++){
                if(prev[j]) curr[j] = true; 
                else if(j >= nums[i] && prev[j-nums[i]]) curr[j] = true;
                else curr[j] = false;
                if(j == total/2 && curr[j]) return true;
            }
            prev = curr;
        }

        return false;
    }
};