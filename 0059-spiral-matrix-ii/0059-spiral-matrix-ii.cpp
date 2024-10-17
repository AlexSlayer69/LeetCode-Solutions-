class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n ,vector<int>(n,0));
        vector<int> dir = {n,n,-1,0};
        int i = 0,j =0,d = 0;
        for(int k = 1;k<=(n*n);k++){
            cout << i << j << k << endl;
            if(d == 0){
                ans[i][j] = k;
                j++;
                if(j == dir[d]){
                    j--;
                    i++;
                    dir[d]--;
                    d = 1;
                }
            }
            else if(d == 1){
                ans[i][j] = k;
                i++;
                if(i == dir[d]){
                    i--;
                    j--;
                    dir[d]--;
                    d = 2;
                }
            }
            else if(d == 2){
                ans[i][j] = k;
                j--;
                if(j == dir[d]){
                    j++;
                    i--;
                    dir[d]++;
                    d = 3;
                }
            }
            else{
                ans[i][j] = k;
                i--;
                if(i == dir[d]){
                    i++;
                    j++;
                    dir[d]++;
                    d = 0;
                }
            }
        }
        return ans;
    }
};