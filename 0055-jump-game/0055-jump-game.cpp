class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int ind = n-1;
        while(ind){
            bool flag = false;
        for(int i = 0;i<ind;i++){
            if(nums[i] + i - ind >= 0){
                ind = i;
                flag = true;
                break;
                }
            }
        if(!flag)
            return false;    
        }
        return true;
    }
};