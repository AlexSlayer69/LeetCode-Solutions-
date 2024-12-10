class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int mi=a[0][0];
        int mx=a[0][a[0].size()-1];
        int ans=0;
         for(int i=1;i<a.size();i++){
            ans=max(ans,mx-a[i][0]);
            ans=max(ans,a[i][a[i].size()-1]-mi);
            if(mi>a[i][0]){
                mi=a[i][0];
            }
            if(mx<a[i][a[i].size()-1]){  
                mx=a[i][a[i].size()-1];
            }
         }
         return ans;
    }
};