class Solution {
public:
int unique_digits = 0;
    int countSpecialNumbers(int n) {
        backtrack(0,0, n);
        return unique_digits-1;
    }
    void backtrack(long cur, int bitmask, int& n){
        if(cur > n) return;
        else unique_digits++;
        
        for(int digit=0; digit<10; digit++){
            if(bitmask == 0 && digit == 0) continue;
            if((bitmask & (1<<digit)) > 0) continue; 
            backtrack(cur*10 + digit, bitmask | (1<<digit), n);
        }
    }
};