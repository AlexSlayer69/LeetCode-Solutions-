typedef long long ll;
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        map<int,int>mp;
        ll ans=0,ng=0;
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[i]){
                ans+=i;
                mp[nums1[i]]++;
                ng++;
            }
        }
        int mx=0,val=-1;
        for(auto[x,f]:mp){
            if(mx<f){
                val=x;
                mx=f;
            }
        }
        int need=mx-(ng-mx);
        for(int i=0;i<n;i++){
            if(need>0&&nums1[i]!=nums2[i]&&nums1[i]!=val&&nums2[i]!=val){
                need--;
                ans+=i;
            }
        }
        if(need>0)ans=-1;
        return ans;
    }
};