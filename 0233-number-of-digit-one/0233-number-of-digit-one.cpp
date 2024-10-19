class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0) return 0;
        if(n < 10) return 1;
        int digit = n;
        int ndigits = 0;
        while(n){
            ndigits++;
            n /= 10;
        }
        n = digit;
        int p = pow(10,ndigits-1);
        int fd  = n/p;
        int ans = countDigitOne(n%p) + fd*countDigitOne(p - 1);
        if(fd == 1) ans += n%p+1;
        else ans += p;  
        return ans;
    }
};