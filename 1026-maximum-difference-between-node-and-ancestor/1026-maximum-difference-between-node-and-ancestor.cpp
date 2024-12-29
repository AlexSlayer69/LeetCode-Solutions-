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
    int maxAncestorDiff(TreeNode* root) {
        int minv = root->val;
        int maxv = root->val;
        return findMax(root, minv, maxv);
    }

private:
    int findMax(TreeNode* root, int minv, int maxv) {
        if (root == NULL) {
            return abs(minv - maxv);
        }
        minv = std::min(minv, root->val);
        maxv = std::max(maxv, root->val);

        int l = findMax(root->left, minv, maxv);
        int r = findMax(root->right, minv, maxv);

        return std::max(l, r);
    }
};