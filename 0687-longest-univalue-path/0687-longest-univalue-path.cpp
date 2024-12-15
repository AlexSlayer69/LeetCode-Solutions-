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
    int ans = 0;
    pair<int, int> dfs (TreeNode* root) {
        if (!root) return {0, 5000};

        pair<int, int> left = dfs(root->left);
        int leftcontinuous = left.first;
        int leftval = left.second;

        pair<int, int> right = dfs(root->right);
        int rightcontinuous = right.first;
        int rightval = right.second;

        ans = max (ans, 1+((rightval == root->val ? rightcontinuous : 0) + (leftval == root->val ? leftcontinuous : 0)));

        int continuous = 1 + max((rightval == root->val ? rightcontinuous : 0), leftval == root->val ? leftcontinuous : 0);

        return {continuous, root->val};
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs (root);
        return ans-1;
    }
};