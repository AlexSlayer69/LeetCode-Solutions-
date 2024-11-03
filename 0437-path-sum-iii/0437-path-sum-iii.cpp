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

    void solve(TreeNode* node ,int curr, int target, 
              unordered_map<long,int> &dp,int &count){
        if(!node) return;
        curr += node->val;
        if(dp.find(curr - target) != dp.end()) count += dp[curr-target];
        dp[curr]++;
        solve(node->left,curr,target,dp,count);
        solve(node->right,curr,target,dp,count);
        dp[curr]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> dp;
        int ans = 0;
        dp[0] = 1;
        solve(root,0,targetSum,dp,ans);
        return ans;
    }
};