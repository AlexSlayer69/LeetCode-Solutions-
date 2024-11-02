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

    int solve(TreeNode * root,int maxi){
        if(!root) return 0;
        if(!root->left && !root->right && maxi <= root->val) return 1;
        int ans = 0;
        if(root->val >= maxi) ans++;
        maxi = max(maxi,root->val);
        return solve(root->left,maxi) + solve(root->right,maxi) + ans;
    }

    int goodNodes(TreeNode* root) {
        return solve(root,-1e5);
    }
};