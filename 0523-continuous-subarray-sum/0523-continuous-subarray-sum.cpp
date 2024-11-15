class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++){
            int it = nums[i];
            sum += it;
            sum %= k;

            if(mp.find(sum) != mp.end()){
                int len = (i+1 - (mp[sum]+1));
                if(len >= 2) return true;
            }
            else mp[sum] = i;
            
        }
        return false;
    }
};