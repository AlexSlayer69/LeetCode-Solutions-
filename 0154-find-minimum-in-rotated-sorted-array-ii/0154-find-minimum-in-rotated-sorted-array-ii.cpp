class Solution {
public:
    int solve(int low,int high,vector<int>& nums){
        if(low==high) return low;

        int mid=(low+high)/2;
        
        if(nums[mid]>nums[high]) return solve(mid+1,high,nums);
        else if(nums[low]<nums[mid]) return solve(low,mid-1,nums);
        else if(nums[low]==nums[mid] && nums[high] != nums[mid]) return solve(mid,high-1,nums);
        else if(nums[low] != nums[mid] && nums[high] == nums[mid]) return solve(low+1,mid,nums);
        else {
            int a = solve(low,mid,nums);
            int b = solve(mid+1,high,nums);
            if(nums[a]<nums[b]) return a;
            return b;
        }
    }

    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return nums[solve(low,high,nums)];
    }
};