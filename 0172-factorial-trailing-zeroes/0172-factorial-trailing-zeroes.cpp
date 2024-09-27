class Solution {
public:
    int trailingZeroes(int n) {
        int k = 5,sum = 0;
        while((n/k) > 0){
            sum += n/k;
            k *= 5;
        }
        return sum;
    }
};