// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int l=0,r=n,ans=INT_MAX;
        while(l<=r){
           long long int mid=(l+r)/2;
            if(isBadVersion(mid)){
                if(ans>mid){
                    ans=mid;
                }
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};