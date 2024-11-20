class Solution {
public:
     void solve(int ind, int k, int n, vector<int>& temp, vector<vector<int>>& dp){
        if(!k||!n){
            if(!k&&!n) dp.push_back(temp);
            return;
        }

        for(int i=ind;i<=9;i++){
            if(n<i) return;
            temp.push_back(i);
            solve(i+1, k-1, n-i, temp, dp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> dp;

        solve(1, k, n, temp, dp);
        return dp;
    }
};