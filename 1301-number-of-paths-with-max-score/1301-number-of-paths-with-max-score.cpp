class Solution {
public:
    int n,m,inf=1e9,mod=1e9+7;
    
    inline bool is(int i,int j)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
    vector<int> pathsWithMaxScore(vector<string>& a) 
    {
        n=a.size(),m=a[0].length();
        a[0][0]='0';
        int dp[n][m]; memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--)
            {
                if(a[i][j]=='S') continue;
                if(a[i][j]=='X')
                {
                    dp[i][j]=-inf;
                    continue;
                }
                
                int mx=-inf;
                if(is(i+1,j) && dp[i+1][j]!=-inf) mx=max(mx,dp[i+1][j]);
                if(is(i,j+1) && dp[i][j+1]!=-inf) mx=max(mx,dp[i][j+1]);
                if(is(i+1,j+1) && dp[i+1][j+1]!=-inf) mx=max(mx,dp[i+1][j+1]);
                
                if(mx!=-inf) dp[i][j]=mx+(a[i][j]-'0');
                else dp[i][j]=-inf;
            }
        
        long cnt[n][m]; memset(cnt,0,sizeof(cnt));
        cnt[0][0]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==-inf) continue;
                int need=dp[i][j]-(a[i][j]-'0');
                cnt[i][j]%=mod;
                if(is(i+1,j) && dp[i+1][j]==need) cnt[i+1][j]+=cnt[i][j],cnt[i+1][j]%=mod;;
                if(is(i,j+1) && dp[i][j+1]==need) cnt[i][j+1]+=cnt[i][j],cnt[i][j+1]%=mod;;
                if(is(i+1,j+1) && dp[i+1][j+1]==need) cnt[i+1][j+1]+=cnt[i][j],cnt[i+1][j+1]%=mod;
            }
        
        if(dp[0][0]<=-inf) dp[0][0]=0;
        vector<int> ans={dp[0][0],(int)cnt[n-1][m-1]};
        return ans;
    }
};