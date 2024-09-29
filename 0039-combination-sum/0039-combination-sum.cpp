class Solution {
public:

    void solve(int i,int t,vector<int>& candidates,vector<int> &sum,vector<vector<int>> &v){
        if(i >= candidates.size()) return;
        if(t < 0) return;
        if(t == 0){
            v.push_back(sum);
            return;
        }
        solve(i+1,t,candidates,sum,v);
        sum.push_back(candidates[i]);
        solve(i,t-candidates[i],candidates,sum,v);
        sum.pop_back();
        return;
    } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> s;
        solve(0,target,candidates,s,ans);
        return ans;
    }
};