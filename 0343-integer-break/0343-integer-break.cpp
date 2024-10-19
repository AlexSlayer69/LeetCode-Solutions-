class Solution {
public:
    int integerBreak(int n) {
        int maxi = 1;
        if(n == 3) return 2;
        for(int k = 1; k < (n+1)/2;k++){
            // int rem = n%k;
            // int same = n/k;
            int candi = (int) pow(n/k+1,n%k) * pow(n/k,k-(n%k));
            maxi = max(candi,maxi);
        }
        return maxi;
    }
};