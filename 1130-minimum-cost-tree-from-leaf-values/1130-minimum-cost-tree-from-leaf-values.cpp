class Solution {
    pair<int,int> sol(int s,int e,vector<int>& arr,vector<vector<pair<int,int>>>& dp){
        if(s>e)return {INT_MAX,0};
        if(s==e)return {arr[s],0};
        if(dp[s][e]!=p)return dp[s][e];
        int ans = INT_MAX;
        pair<int,int> a,b;
        int maxi=0;
        for(int i=s;i<e;i++){
            a=sol(s,i,arr,dp);
            b=sol(i+1,e,arr,dp);
            if(a.first==INT_MAX||b.first==INT_MAX)continue;
            ans=min(ans,a.first*b.first + a.second + b.second);
            maxi=max(maxi,max(a.first,b.first));
        }
        return dp[s][e]={maxi,ans};
    }
    
public:
    pair<int,int> p={-1,-1};
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,p));
        int s=0;
        int e = n-1;
        return sol(s,e,arr,dp).second;
        
        
    }
};