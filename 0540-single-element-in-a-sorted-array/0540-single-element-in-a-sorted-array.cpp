class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int l = 0;
        int r = n - 1;
        while(l < r){
            int m = (r+l)/2;
            if(m == 0 && nums[m] != nums[m+1]) return nums[m];
            else if(m == n-1 && nums[m] != nums[m-1]) return nums[m];
            else if(nums[m] != nums[m-1] && nums[m] != nums[m+1])    
                return nums[m];
            else if(nums[m] == nums[m-1]){
                if((m-l+1)%2 == 1) r = m;
                else l = m+1;
            }    
            else if(nums[m] == nums[m+1]){ 
             if((r-m+1)%2 == 1) l = m; 
             else r = m-1;
            }
        }
        return nums[l];
    }
};