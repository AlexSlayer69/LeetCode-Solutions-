class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i] ? 1 : -1;
            if(mp.find(sum) != mp.end()) ans  = max(ans, i - mp[sum]); 
            else mp[sum] = i;
        }
        return ans;
    }
};