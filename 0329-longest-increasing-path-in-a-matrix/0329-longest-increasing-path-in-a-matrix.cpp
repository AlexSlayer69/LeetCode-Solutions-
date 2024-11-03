class Solution {
public:

    int solve(int i,int j, vector<vector<int>> &dp,vector<vector<int>>& matrix){
        //cout << i << j << endl;
        if(dp[i][j] != -1) return dp[i][j];
        else{
            vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            int c = 1;
            for(int k = 0; k < 4;k++){
                int nx = i + dir[k].first;
                int ny = j + dir[k].second;
                if(nx >= dp.size() || nx < 0 || ny < 0 || ny >= dp[0].size()) continue;
                else{
                    if(matrix[nx][ny] > matrix[i][j]) c = max(1 + solve(nx,ny,dp,matrix),c);
                }    
            }
            dp[i][j] = c;
            return dp[i][j];   
        }
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans = max(ans,solve(i,j,dp,matrix));
            }
        }
        return ans;
    }
};