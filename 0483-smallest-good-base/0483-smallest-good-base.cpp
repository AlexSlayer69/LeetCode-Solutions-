class Solution {
public:
    string smallestGoodBase(string s) {
        long long n=stol(s);
        for(int i=32;i>2;i--){
            long long val=(sqrtl(n));
            long long taken=1e9+0;
            long long l=2,r=(val,taken);
            while(l<=r){
                   long long mid=(l+r)/2;
                   int cnt1=0;
                   long long have=n;
                   bool  check=true;

                   while(have>0){
                     if(have%mid!=1) check=false;
                     cnt1++;
                     have/=mid;
                   }

                   if(check&&cnt1>2){
                      return to_string(mid);
                   }
                   else{
                     if(cnt1>=i) l=mid+1;
                     else r=mid-1;
                   }
                  
            }
            
        }
           return to_string(n-1);
    }
};