class Solution {
public:
    
    bool solve(vector<int>& nums, int k, int mid){
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=mid) temp += nums[i];
            else{
                if(nums[i]<=mid) temp = nums[i];
                else return false;
                k--;
            }
            if(k < 0) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it : nums) sum += it;

        int l = 0, r = sum;
        int ans = sum;
        while(l<=r){
            int mid = (l+r)/2;
            if(solve(nums,k-1,mid)){
                ans = min(mid,ans);
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};