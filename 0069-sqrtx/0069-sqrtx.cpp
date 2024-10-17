class Solution {
public:
    int mySqrt(int x) {
        long i = 1;
        while(i*i != x && !((i+1)*(i+1) > x && i*i < x)){
            i = (i + x/i)/2;
        }
        return (int) i; 
    }
};