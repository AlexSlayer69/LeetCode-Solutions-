class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long one = 1;
        long long nine = 9;
        while(n > digits*nine){
            n -= digits*nine;
            digits++;
            one *= 10;
            nine *= 10;
        }

        long long num = one + (n-1)/digits;
        return (to_string(num)[(n-1)%digits] - '0');
    }
};