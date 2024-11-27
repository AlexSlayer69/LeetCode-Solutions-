class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        unordered_map<int,int> mp;
        vector<int> v = spells;
        sort(v.begin(),v.end());
        sort(potions.begin(),potions.end(),greater<int>());
        int n = spells.size();
        vector<int> ans(n,0);
        int j = 0;
        for(int i = 0;i<n;i++){
            while(j < potions.size() && (long long)potions[j]*v[i] >= (long long )success) j++;
            mp[v[i]] = j;
        }
        for(int i =0;i<n;i++){
            ans[i] = mp[spells[i]];
        }
    return ans;
    }
};