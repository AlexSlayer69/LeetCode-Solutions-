class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int a = 0;
        int count = 0;
        int l =0;
        int r = n-1;
        sort(nums.begin(),nums.end());
        while(l < r){
            a = nums[l] + nums[r];
            if(a == k) {
                count++;
                l++;
                r--;
            }
            else if(a > k) r--;
            else if(a < k) i++;
        }
        return count;
    }
};