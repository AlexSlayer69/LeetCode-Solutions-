
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = (int)sqrt(c);
        int a = 0;
        while (a <= b) {
            long int x = (long int)(a * a) + (long int)(b * b);
            if (x == c) {
                return true;
            } else if (x > c) {
                b--;
            } else {
                a++;
            }
        }
        return false;
    }
};