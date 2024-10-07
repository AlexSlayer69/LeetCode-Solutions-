class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     int n = nums.size();
     int count = 0;
     unordered_map<int,int> mp;
     int sum = 0;
     for(int i = 0;i < n;i++){
        sum += nums[i];
        if(sum == k){
            count++;
        }
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){
            count += mp[rem];
        }
        // else if(mp.find(-rem) != mp.end()){
        //     cout << i << endl;
        //     }
        mp[sum]++;
     }   
     return count;
    }
};