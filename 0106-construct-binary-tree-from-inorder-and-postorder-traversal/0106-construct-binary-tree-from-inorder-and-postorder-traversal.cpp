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

    TreeNode* build (vector<int>& inorder, vector<int>& postorder, int i1, int j1, int i2, int j2, unordered_map <int, int> &map) {
        if (i1 > j1) return nullptr;
        TreeNode* node = new TreeNode (postorder[j2]);
        int k = map[postorder[j2]];
        node->left = build (inorder, postorder, i1, k-1, i2, i2+k-i1-1, map);
        node->right = build (inorder, postorder, k+1, j1, i2+k-i1, j2-1, map);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return nullptr;
        int n = inorder.size();
        unordered_map <int, int> map;
        for (int i=0; i<n; i++) map[inorder[i]] = i;
        return build (inorder, postorder, 0, n-1, 0, n-1, map);
    }
};