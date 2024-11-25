/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<vector<TreeNode*>>> dp;
    
    vector<TreeNode*> solve(int l,int r){
        if(l>r) return {NULL};
        if(l == r) return {new TreeNode(l)};

        if(dp[l][r].size() > 0) return dp[l][r];

        vector<TreeNode *>ans;
        for(int i = l;i<=r;i++){
            vector<TreeNode*> left = solve(l,i-1);
            vector<TreeNode*> right = solve(i+1,r);
            
            for(auto k:left){
                for(auto m:right){
                    TreeNode *node =new TreeNode(i,k,m);
                    ans.push_back(node);
                }
            }
        }
        return dp[l][r] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        dp.assign(n+1, vector(n+1, vector<TreeNode*>()));
        return solve(1, n);
    }
};