class Solution {
public:

    void solve(int i,int t,vector<int>& candidates,vector<int> &sum,set<vector<int>> &v){
        if(i == candidates.size() && t != 0) return;
        if(i > candidates.size()) return;
        if(t < 0) return;
        if(t == 0){
            sort(sum.begin(),sum.end());
            v.insert(sum);
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
        set<vector<int>> ans2;
        vector<int> s;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,s,ans2);
        for(auto it : ans2){
            ans.push_back(it);
        }
        return ans;
    }
};