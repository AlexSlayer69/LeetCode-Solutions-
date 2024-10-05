class Solution {
public:

    int nCr(int n ,int r){
        double prod = 1.0;
        for(int i = 0;i<r;i++)prod *= (n-i)*1.0/(r-i);
        return (int) round(prod);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,0);
        for(int i =0;i<=rowIndex;i++){
            v[i] = nCr(rowIndex,i);
        }
        return v;
    }
};