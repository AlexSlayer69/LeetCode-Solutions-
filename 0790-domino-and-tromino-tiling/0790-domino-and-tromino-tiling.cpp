#define vi vector<int>
#define UL unsigned long

class Solution {
public:
    const int m = 1e9 + 7;
    vi MR, MNRD;

    int add(UL a, UL b) { return ((a % m) + (b % m)) % m; }

    int dfsRec(int n) {
        if(n <= 1) return n >= 0;
        if(MR[n] >= 0) return MR[n];
        auto rec = add(dfsRec(n - 1), dfsRec(n - 2));
        auto nonRec = add(dfsNonRecDown(n - 1), dfsNonRecUp(n - 1));
        return MR[n] = add(rec, nonRec);
    }

    int dfsNonRecDown(int n) {
        if(n <= 2) return n == 2;
        if(MNRD[n] >= 0) return MNRD[n];
        return MNRD[n] = add(dfsNonRecUp(n - 1), dfsRec(n - 2));
    }

    int dfsNonRecUp(int n) {
        return add(dfsNonRecDown(n - 1), dfsRec(n - 2));
    }

    int dfs(int n) {
        MR.resize(n + 1, -1), MNRD.resize(n + 1, -1);
        return dfsRec(n);
    }

    int numTilings(int n) {
        return dfs(n);
    }
};