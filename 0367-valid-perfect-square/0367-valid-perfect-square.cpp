class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        int l = 1;
        int h = num/2;
        while(l <= h){
            int m = (l+h)/2;
            if((double) num/m == m) return true;
            if((double) num/m < m) h = m-1;
            else l = m + 1;
        }
        return false;
    }
};