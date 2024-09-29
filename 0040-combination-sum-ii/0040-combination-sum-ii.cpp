class Solution {
public:

    void solve(int i,int t,vector<int>& candidates,vector<int> &sum,vector<vector<int>> &v){
        if(i == candidates.size() && t != 0) return;
        if(i > candidates.size()) return;
        if(t < 0) return;
        if(t == 0){
            v.push_back(sum);
            return;
        }
        sum.push_back(candidates[i]);
        solve(i+1,t-candidates[i],candidates,sum,v);
        sum.pop_back();
        while(i < candidates.size()-1 && candidates[i] == candidates[i+1]) i++;
        solve(i+1,t,candidates,sum,v);
        return;
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> s;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,s,ans);
        return ans;
    }
};