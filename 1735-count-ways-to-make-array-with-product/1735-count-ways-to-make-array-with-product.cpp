class Solution {
public:
    const static int N = 1e4 + 14;
    const int mod = 1e9 + 7;
    int spf[N], comb[N][14];;

    void precomputeSPF(){
        for (int i=0; i<N; i++){
            spf[i] = i;
        }
        for (int i=2; i<N; i++){
            if (spf[i] == i){
                for (int j=2*i; j<N; j+=i){
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    vector<int> waysToFillArray(vector<vector<int>>& que) {
        int n, k, r, fac;
        vector<int> ans(que.size(),1);
        precomputeSPF();

        for (int n = 0; n < 10014; n++){
            comb[n][0] = 1;
            for (int r = 1; n > 0 && r < 14; r++){
                comb[n][r] = (comb[n-1][r-1] + comb[n-1][r]) % mod;
            }
        }

        for (int i=0; i<que.size(); i++){
            n = que[i][0];
            k = que[i][1];
            while (k != 1){
                fac = spf[k];
                r = 0;
                while (k % fac == 0){
                    k /= fac;
                    r += 1;
                }
                ans[i] = (long long)ans[i] * comb[n+r-1][r] % mod;
            }
        }
        return ans;
    }
};