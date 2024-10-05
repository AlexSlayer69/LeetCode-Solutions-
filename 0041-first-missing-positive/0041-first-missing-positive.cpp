class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(abs(nums[i])<=n){
                nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
            return i+1;
        }
        return n+1;
    }
};