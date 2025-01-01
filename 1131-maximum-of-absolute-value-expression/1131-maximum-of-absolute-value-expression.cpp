class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        multiset<int> a;
        multiset<int> b;
        multiset<int> c;
        multiset<int> d;

        for(int i = 0; i < n; i++){
            a.insert(arr1[i]+arr2[i]+i);
            b.insert(arr1[i]+arr2[i]-i);
            c.insert(arr1[i]-arr2[i]+i);
            d.insert(arr1[i]-arr2[i]-i);
        }

        int max_res = INT_MIN;
        max_res = max(max_res, *a.rbegin()-*a.begin());
        max_res = max(max_res, *b.rbegin()-*b.begin());
        max_res = max(max_res, *c.rbegin()-*c.begin());
        max_res = max(max_res, *d.rbegin()-*d.begin());
        return max_res;
    }
};