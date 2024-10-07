class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> border(4, 0);
        border[0] = m-1, border[1] = n-1, border[2] = 0, border[3] = 1;
        int dir = 0;
        vector<int> ans;
        int i = 0, j = 0;
        for (int k = 0; k < n * m; k++) {
            //cout << i << j << k << dir << endl;
            ans.push_back(matrix[i][j]);
            
            switch (dir) {
            case 0:
                if (j < border[dir]) j++;
                else{
                    i++;
                    border[dir]--;
                    dir++;
                } 
                break;
            case 1:
                if (i < border[dir])i++;
                else{
                    j--;
                    border[dir]--;
                    dir++;
                }
                break;
            case 2:
                if (j > border[dir]) j--;
                else {
                    i--;
                    border[dir]++;
                    dir++;
                }
                break;
            case 3:
                if (i > border[dir]) i--;
                else {
                    j++;
                    border[dir]++;
                    dir = 0;
                }
                break;
            default:
                break;
            }
        }
        return ans;
    }
};