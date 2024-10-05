class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(auto it : nums) mp[it]++;

        for(int i=1;i<=n+1;i++){
               if(mp[i] == 0) return i;
        }

     return n+1;   
    }
};