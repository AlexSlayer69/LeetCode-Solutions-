
class NumMatrix {
public:
    int v[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                v[i][j]=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                v[i+1][j+1]=v[i][j+1]+v[i+1][j]-v[i][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, col1++;
        row2++, col2++;
        
        int ans=v[row2][col2];
        ans-=v[row1-1][col2];
        ans-=v[row2][col1-1];
        ans+=v[row1-1][col1-1];
        
        return ans;
    }
};