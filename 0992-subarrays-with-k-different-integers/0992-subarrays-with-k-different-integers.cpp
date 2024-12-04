class Solution {
public:
    long long pre(vector<int>& nm, int k){
        unordered_map<int, int> mp;
        long long cnt=0, ans=0, r=0, l=0, n=nm.size();
        while(r<n){
            mp[nm[r]]++;
            while(mp.size()>k){
                mp[nm[l]]--;
                if(mp[nm[l]]==0){
                    mp.erase(nm[l]);
                }
                l++;
            }
            cnt+=r-l+1;
            r++;
        } return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nm, int k) {
        return pre(nm, k)-pre(nm, k-1);
    }
};