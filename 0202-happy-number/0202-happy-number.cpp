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
        unordered_map<int,bool> mp;
        int a = sq(n);
        while(a != 1){
            if(mp.find(a) != mp.end()) return false;
            mp[a] = true;    
            a = sq(a);
        }
        return true;
    }
};