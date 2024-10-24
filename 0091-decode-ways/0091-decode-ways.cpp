class Solution {
public:
    unordered_map<string,int> dp;
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1 && s[0] == '0') return 0;
        if(n == 1 || n == 0) return 1;
        else { 
            if(dp.find(s) != dp.end()) return dp[s];
            if(s[0] == '0') {
                dp[s] = 0;
                return dp[s];
            }
            int ans = 0;
            ans = numDecodings(s.substr(1,n-1));
            int k = stoi(s.substr(0,2));
            if(k > 0 && k < 27)  ans += numDecodings(s.substr(2,n-2));
            dp[s] = ans;
            return dp[s];    
        }
    }
};