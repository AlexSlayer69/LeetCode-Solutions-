class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n,0);
        for(int i = 1;i<=n;i++) a[i-1] = i;

        for(int i = 1;i<k;i++) next_permutation(a.begin(),a.end());

        string s = "";
        for(auto it : a) s += (it + '0');
        return s;
    }
};