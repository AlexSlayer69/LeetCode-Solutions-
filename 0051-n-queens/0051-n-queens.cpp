class Solution {
public:

    void solve(int c, vector <string> &board, vector <vector<string>> &ans, vector <int> &lr, vector <int> &ud, 
    vector <int> &ld, int n){
      
        if (c == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (lr[i] == 0 && ld[i + c] == 0 && ud[n - 1 + c - i] == 0) {
            board[i][c] = 'Q';
            lr[i] = 1;
            ld[i + c] = 1;
            ud[n - 1 + c - i] = 1;
            solve(c + 1, board, ans, lr, ud, ld, n);
            board[i][c] = '.';
            lr[i] = 0;
            ld[i+c] = 0;
            ud[n - 1 + c - i] = 0;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) board[i] = s;
        vector <int> lr(n, 0), ud(2 * n - 1, 0), ld(2 * n - 1, 0);
        solve(0, board, ans, lr, ud, ld, n);
        return ans;
    }
};