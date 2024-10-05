class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows 
        for(int i =0;i<9;i++){
            vector<int> v(9,0);
            for(int j =0;j<9;j++){
                if(board[i][j] != '.'){
                    if(v[board[i][j] - '1'] == 1) return false;
                    v[board[i][j] - '1']++;
                }
            }
        }
        //cols 
        for(int i =0;i<9;i++){
            vector<int> v(9,0);
            for(int j =0;j<9;j++){
                if(board[j][i] != '.'){
                    if(v[board[j][i] - '1'] == 1) return false;
                    v[board[j][i] - '1']++;
                }
            }
        }
        // 3x3 
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                vector<int> v(9,0);
                for(int k = 0;k<3;k++){
                    for(int l =0;l<3;l++){
                         if(board[k+(3*i)][l+(3*j)] != '.'){
                            if(v[board[k+(3*i)][l+(3*j)] - '1'] == 1)return false;
                            v[board[k+(3*i)][l+(3*j)] - '1']++;
                        }
                    }
                }
            }
        }
        return true;
    }
};