class Solution {
public:

    bool palindrome(string &s,int l,int r,pair<int,int> &a,vector<vector<int>> &dp){
        int n = r-l+1;
        for(int i = 0;i < (n/2);i++){
            if(s[l+i] != s[l+n-i-1]) {
                dp[l][r] = 0;
                return false;
                }
        }

        dp[l][r] = 1;
        if(a.second - a.first < r-l) a = {l,r};
        return true;
    }

    void recPalindrome(string &s,int i,int j,pair<int,int> &p,vector<vector<int>> &dp){
        if(j <= i || dp[i][j] == 1) return;
        if(dp[i][j] == -1) palindrome(s,i,j,p,dp);
        if(dp[i+1][j] == -1) recPalindrome(s,i+1,j,p,dp);
        if(dp[i][j-1] == -1) recPalindrome(s,i,j-1,p,dp);
        return;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        vector< vector<int> > dp;
        for(int i =0;i<n;i++){
            vector<int> temp(n,-1);
            dp.push_back(temp);
        }
        pair<int,int> maxran = {0,0};
        recPalindrome(s,0,n-1,maxran,dp);
        return s.substr(maxran.first,maxran.second-maxran.first+1);
    }
};