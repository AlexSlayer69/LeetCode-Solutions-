using int2=pair<int,int>;
vector<int2> moves={{1,2},{2, 1},{-1,2},{-2, 1},{1,-2},{2, -1},{-1,-2},{-2, -1}};
class Solution {
public:
    vector<vector<vector<double>>> dp;
    double knight(int n, int k, int i, int j){
        if (i<0 || i>=n || j<0 || j>=n) return 0;
        if (k==0) return dp[0][i][j]=1;
        if (dp[k][i][j]!=-1) return dp[k][i][j];
        double prob=0;
        for (auto [a,b]: moves){
            int r=i+a, s=j+b;
            prob+=1.0/8*knight(n, k-1, r, s);
        }
        return dp[k][i][j]=prob;
    }
   
    double knightProbability(int n, int k, int row, int column) {
        dp.assign(k+1, vector(n, vector<double>(n, -1.0)));
        return knight(n, k, row, column);
    }
};