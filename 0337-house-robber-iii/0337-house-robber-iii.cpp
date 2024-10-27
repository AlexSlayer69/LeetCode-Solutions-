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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        if(root->left && !root->right){
            mp[root] = max(root->val+rob(root->left->left)+rob(root->left->right),
                        rob(root->left));
        } 
        else if(root->right && !root->left){
            mp[root] = max(root->val+rob(root->right->left)+rob(root->right->right),
            rob(root->right));
        }
        else if(!root->left && !root->right) mp[root] = root->val;
        else{
            mp[root] = max(root->val+rob(root->right->left)+rob(root->right->right)
            +rob(root->left->left)+rob(root->left->right),rob(root->left) + rob(root->right));
        }
        return mp[root];
    }
};