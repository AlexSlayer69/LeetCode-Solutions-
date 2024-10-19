class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        if(gcd(x,y) == 1 && x+y >= target) return true;
        if(target%gcd(x,y) == 0) return true;
        return false;
    }
};