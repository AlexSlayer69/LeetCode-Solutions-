class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(next_permutation(nums)){
            ans.push_back(nums);
        }
        return ans;
    }
};