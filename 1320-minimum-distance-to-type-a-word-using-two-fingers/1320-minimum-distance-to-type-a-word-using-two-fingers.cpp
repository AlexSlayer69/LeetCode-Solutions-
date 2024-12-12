class Solution {
public:
    int solve(int i,int leftI,int rightI,string &word,vector<vector<vector<int>>> &dp){
        if(i==word.size())  return 0;

        if(leftI!=-1 && rightI!=-1 && dp[i][leftI][rightI]!=-1) 
            return dp[i][leftI][rightI];

        int pos = word[i]-'A';
        int posX=pos/6, posY=pos%6;

        int leftIX=leftI/6, leftIY=leftI%6;
        int rightIX=rightI/6, rightIY=rightI%6;

        int left = 1e9;
        if(leftI!=-1)   
            left = abs(leftIX-posX) + abs(leftIY-posY) + solve(i+1,pos,rightI,word,dp);
        else    left = 0 + solve(i+1,pos,rightI,word,dp);

        int right = 1e9;
        if(rightI!=-1)  
            right = abs(rightIX-posX) + abs(rightIY-posY) + solve(i+1,leftI,pos,word,dp);
        else    right = 0 + solve(i+1,leftI,pos,word,dp);

        if(leftI==-1 || rightI==-1) return min(left,right);
        return dp[i][leftI][rightI] = min(left,right);
    }
    int minimumDistance(string word) {
        int n=word.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
        return solve(0,-1,-1,word,dp);
    }
};