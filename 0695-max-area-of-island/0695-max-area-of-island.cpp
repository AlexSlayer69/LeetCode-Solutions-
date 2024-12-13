class Solution {
public:
    int dfs(vector<vector<int>>& mat,int i,int j){
      
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() 
           || mat[i][j]== -1 || mat[i][j]==0   ){
            return 0;
        }
           
      
        mat[i][j] = -1; 
        
        int a=dfs(mat,i+1,j);
        int b=dfs(mat,i-1,j);
        int c=dfs(mat,i,j+1);
        int d=dfs(mat,i,j-1);
        
        return 1 + a+b+c+d;
    }
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        
        int ans=0;
        
        for(int i=0; i<r; i++){
            
            for(int j=0; j<c; j++){

                if(mat[i][j] == 1){
                    int curr = dfs(mat,i,j);  
                    ans = max(ans,curr);
                }
            }
        }
        
        return ans;
    }
};