class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(),m = board[0].size();
        map<pair<int,int>,bool> mp;

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 1) mp[{i,j}] = true;
            }
        }

        vector<int> dir = {-1,0,1};
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mp[{i,j}]){
                    board[i][j]--;
                    for(int k = 0;k<3;k++){
                        for(int l = 0;l<3;l++){
                            if(!(k == 0 && l == 0) && i+k >=0 && i+k <= n-1 
                                && j+l >=0 && j+l <= m-1)
                                    board[i+k][j+l]++;
                        }
                    }
                }
            }
        }

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 3) board[i][j] = 1;
                if(board[i][j] == 2) {
                    if(mp[{i,j}]) board[i][j] = 1;
                    else board[i][j] = 0;
                }
                else board[i][j] = 0;
            }
        }

    }
};