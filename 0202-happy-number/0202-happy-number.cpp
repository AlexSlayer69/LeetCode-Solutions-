class Solution {
public:

    int sq(int n){
        int sum = 0;
        while(n > 0){
            int sq = n%10;
            sum += sq*sq;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> s;
        int a = sq(n);
        while(a != 1){
            if(s.find(a) != s.end()) return false;
            s.insert(a);   
            a = sq(a);
        }
        return true;
    }
};