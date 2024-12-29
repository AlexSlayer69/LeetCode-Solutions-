class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
       long long int s=1,pp=0,cnt=0;
        while(s){
           pp=(pp*10)%k+1;
           if(pp%k==0) return cnt+1;
           cnt++;
        }
        return -1;
    }
};