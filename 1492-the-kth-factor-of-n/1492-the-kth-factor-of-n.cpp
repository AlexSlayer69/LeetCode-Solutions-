class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0,i=n;
        while(cnt < k){
            if(i == 0)
                return -1;
            if(n%i == 0)
                cnt++;
            i--;    
        }
        return n/(i+1);
    }
};