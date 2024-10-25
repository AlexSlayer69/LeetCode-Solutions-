class Solution {
public:

    int helper(int a,int b,string &word1, string &word2,vector<vector<int>> &dp){
        if(a == -1 && b == -1) return 0;
        if(a == -1) return b+1;
        if(b == -1) return a+1;
        if(dp[a][b] != -1) return dp[a][b];
        else{
            int cost = (word1[a] == word2[b]) ? 0 : 1;
            dp[a][b] = min(helper(a,b-1,word1,word2,dp) + 1,
                       min(helper(a-1,b,word1,word2,dp)+1,
                           helper(a-1,b-1,word1,word2,dp) + cost));
        }
        return dp[a][b];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(n-1,m-1,word1,word2,dp);
    }
};