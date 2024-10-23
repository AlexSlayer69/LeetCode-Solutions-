class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<32;i++){
            int sum = 0 ;
            for(int k = 0 ;k < nums.size();k++) sum += (nums[k]>>i)&1;
            ans += sum * (nums.size()-sum);
        }
        return ans;
    }
};