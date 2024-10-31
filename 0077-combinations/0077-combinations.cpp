class Solution {
public:
    
    void backtrack(int i, vector<int> &temp, vector<vector<int>> &ans, int n, int k) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j <= n; j++) {
            temp.push_back(j);
            backtrack(j + 1,temp,ans,n,k);
            temp.pop_back();
        }
    }    

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(1,temp,ans,n,k)
        return ans;
    }
};