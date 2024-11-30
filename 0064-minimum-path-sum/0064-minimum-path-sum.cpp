class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int bottomRight = grid[rows - 1][cols - 1];
        
        for (int i = rows - 2; i >= 0; i--) {
            grid[i][cols - 1] += bottomRight;
            bottomRight = grid[i][cols - 1];
        }
        
        bottomRight = grid[rows - 1][cols - 1];
        
        for (int j = cols - 2; j >= 0; j--) {
            grid[rows - 1][j] += bottomRight;
            bottomRight = grid[rows - 1][j];
        }

        for (int i = rows - 2; i >= 0; i--) {
            for (int j = cols - 2; j >= 0; j--) {
                int down = grid[i + 1][j];
                int right = grid[i][j + 1];
                grid[i][j] += min(down, right);
            }
        }
        
        return grid[0][0];
    }
};