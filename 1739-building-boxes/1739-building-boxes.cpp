class Solution {
public:
    int minimumBoxes(int n) {
        int st=1;
        int end=1e8;
        int mid=st+(end-st)/2;
        int ans=1;
        while(st<=end){
            mid=st+(end-st)/2;
            int x=ceil(sqrt(2.0*mid));
            long long sum=x*(x+1)/2;
            while(sum>mid){
                x--;
                sum=x*(x+1)/2;
            }
            int y=mid-sum;
            long long s=0;
            while(n>s && x){
                s+=sum+y;
                if(s>=n) break;
                sum-=x;
                y=max(0,y-1);
                x--;
            }
            if(s>=n){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }

        return ans;
    }
};