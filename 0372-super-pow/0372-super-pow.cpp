class Solution {
public:
    int fastexp(long a, int k) {
        int mod = 1e9 + 7;
        a %= mod;
        int ans = 1;
        for (int i = 0; i < k; i++) ans = (long long)(ans%mod * a%mod) % mod;
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int mod = 1e9 + 7;
        int l = b.back();
        b.pop_back();
        
        int temp1 = fastexp(superPow(a, b), 10);
        int temp2 = fastexp(a, l);
        
        return (temp1 * temp2) % mod;
    }
};