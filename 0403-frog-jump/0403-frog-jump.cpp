class Solution {
public:

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector< unordered_set<int> > dp(n, unordered_set<int>());
        dp[0].insert(0);
        if(stones[1] == 1)
            dp[1].insert(1);
        else 
            return false;   

        for(int i = 1;i < n;i++){
            if(dp[i].empty()) continue;
            for(int k : dp[i]){
                if(k-1 < 0) continue; 
                if(k != 0){
                    auto l = find(stones.begin(),stones.end(),stones[i] + k);
                    if(l != stones.end()) dp[l - stones.begin()].insert(k);
                }         
                if(k-1 != 0){
                    auto l = find(stones.begin(),stones.end(),stones[i] + k-1);
                    if(l != stones.end()) dp[l - stones.begin()].insert(k-1);
                } 
                auto l = find(stones.begin(),stones.end(),stones[i] + k+1);
                if(l != stones.end()) dp[l - stones.begin()].insert(k+1);
                }
            }

        return !dp[n-1].empty();
    }
};