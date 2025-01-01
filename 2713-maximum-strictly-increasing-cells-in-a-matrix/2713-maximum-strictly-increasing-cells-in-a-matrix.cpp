class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<vector<int>> maxIncreasingCells(mat.size(),vector<int>(mat[0].size()));
        vector<int> maxRow(mat.size());
        vector<int> maxCol(mat[0].size());
        vector<vector<int>> elementsIndex;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                elementsIndex.push_back({mat[i][j],i,j});
            }
        }
        int ans=0;
        vector<vector<int>> st;
        sort(elementsIndex.begin(),elementsIndex.end(),greater<vector<int>>());
        for(int i=0;i<elementsIndex.size();i++){
            int element=elementsIndex[i][0];
            int row=elementsIndex[i][1];
            int col=elementsIndex[i][2];
            maxIncreasingCells[row][col]=max(maxRow[row],maxCol[col])+1;
            ans=max(ans,maxIncreasingCells[row][col]);
            if(i!=elementsIndex.size()-1 && elementsIndex[i][0]==elementsIndex[i+1][0]){
                st.push_back({row,col,maxIncreasingCells[row][col]});
                continue;
            }
            while(st.size()){
                int r=st.back()[0];
                int c=st.back()[1];
                int val=st.back()[2];
                maxRow[r]=max(maxRow[r],val);
                maxCol[c]=max(maxCol[c],val);
                st.pop_back();
            }
            maxRow[row]=max(maxRow[row],maxIncreasingCells[row][col]);
            maxCol[col]=max(maxCol[col],maxIncreasingCells[row][col]);
        }
        return ans;
    }
};