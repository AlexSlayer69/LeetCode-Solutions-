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

    int solve(TreeNode* root, int c){
        if (!root) return 0;
        c = c * 10 + root->val;
        if (!root->left && !root->right) return c;
        return solve(root->left, c) + solve(root->right, c);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};