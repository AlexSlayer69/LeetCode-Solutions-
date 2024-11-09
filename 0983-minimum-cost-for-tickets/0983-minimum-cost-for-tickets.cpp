class Solution {
public:

    int solve(int i,vector<int>& costs,vector<int>& days,vector<int> &dp){
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int one = costs[0] + solve(i+1,costs,days,dp);
        int j = i+1;
        while(j < days.size() && days[j] <= days[i]+6) j++;
        int seven = costs[1] + solve(j,costs,days,dp);
        //int j = i+1;
        while(j < days.size() && days[j] <= days[i]+29) j++;
        int th = costs[2] + solve(j,costs,days,dp);
        dp[i] = min(one,min(seven,th));
        //cout << i << " " << dp[i] << endl;
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return solve(0,costs,days,dp);
    }
};