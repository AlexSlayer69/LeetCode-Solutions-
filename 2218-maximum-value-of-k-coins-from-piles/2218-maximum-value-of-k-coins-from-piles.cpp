class Solution {
int t[1001][2002];
public:
    int solve(int i, int k, vector<vector<int>>& piles, int n){
        if (i==n or k<=0)return 0;
        if (t[i][k]!=-1){return t[i][k];}
        int ans = solve(i+1,k,piles,n);
        int temp = 0;
        for (int kk=0;kk<min((int)piles[i].size(),k);kk++){
            temp+=piles[i][kk];
            ans=max(ans,temp + solve(i+1,k-1-kk,piles,n));
        }
        return t[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memset(t,-1,sizeof(t));
        return solve(0,k,piles,n);
    }
};