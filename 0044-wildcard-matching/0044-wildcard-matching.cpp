class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<bool>prev(m+1,false);
        vector<bool>curr(m+1,false);
        prev[0]=true;
    
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') prev[i]=true;
            else break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    curr[j]=prev[j-1];
                else if(p[j-1]=='*')
                    curr[j]=curr[j-1] || prev[j];
                else
                    curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};