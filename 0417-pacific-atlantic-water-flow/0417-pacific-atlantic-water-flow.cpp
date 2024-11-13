class Solution {
public:

    bool isReachable(int i, int j, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }

    void solve(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j, int m, int n) {
        if(!isReachable(i, j, m, n) || ocean[i][j]!=-1) return;

        ocean[i][j] = 1;

        // If any neighbouring cell is in bounds and the height is greater than current height, it can reach current ocean
        if(isReachable(i-1, j, m, n) && heights[i-1][j]>=heights[i][j]) solve(heights, ocean, i-1, j, m, n);
        if(isReachable(i+1, j, m, n) && heights[i+1][j]>=heights[i][j]) solve(heights, ocean, i+1, j, m, n);
        if(isReachable(i, j-1, m, n) && heights[i][j-1]>=heights[i][j]) solve(heights, ocean, i, j-1, m, n);
        if(isReachable(i, j+1, m, n) && heights[i][j+1]>=heights[i][j]) solve(heights, ocean, i, j+1, m, n);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, -1)),atlantic(m, vector<int>(n, -1));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 || j==0) solve(heights, pacific, i, j, m, n);
                if(i==m-1 || j==n-1) solve(heights, atlantic, i, j, m, n);
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(pacific[i][j]==1 && atlantic[i][j]==1) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};