class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n = nums.size() , k=0;
       for(int i = 0;i<n;i++)
         k ^= nums[i];
       return k;
    }
};