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

    void leaves(TreeNode* root,vector<int> &v){
        if(!root) return;
        else if(!root->left && !root->right) v.push_back(root->val);
        else{
            leaves(root->left,v);
            leaves(root->right,v);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        leaves(root1,v1);
        leaves(root2,v2);
        return (v1 == v2) ? true : false;
    }
};