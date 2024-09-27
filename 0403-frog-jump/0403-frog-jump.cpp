class Solution {
public:

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<  unordered_set<int> > dp(n, unordered_set<int>());
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
                    if(l != stones.end()){
                        dp[l - stones.begin()].insert(k);
                        cout << '[' << i << "," << k << "," << l-stones.begin() << "]" <<endl;
                    } 
                }         
                if(k-1 != 0){
                    auto l = find(stones.begin(),stones.end(),stones[i] + k-1);
                    if(l != stones.end()){
                        cout << '[' << i << "," << k-1 << "," << l-stones.begin() << "]" <<endl;
                        dp[l - stones.begin()].insert(k-1);
                    }
                } 
                if(1){
                    auto l = find(stones.begin(),stones.end(),stones[i] + k+1);
                    if(l != stones.end()){
                        dp[l - stones.begin()].insert(k+1);
                        cout << '[' << i << "," << k+1 << "," << l-stones.begin() << "]" <<endl;
                    }
                }
            }
        }
        cout << "[" << endl;
        for(int i = 0;i < n;i++){
            cout << "[";
            for(auto it: dp[i])
                cout << " " << it << ",";
            cout << " ]," << endl;     
        }
        cout << "]";

        return !dp[n-1].empty();
    }
};