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

    void invert(TreeNode* root){
        if(!root) return;
        swap(root->left,root->right);
        invert(root->left);
        invert(root->right);
        return;
        // if(!root->left && !root->right) return;
        // if(!root->left){
        //     root->left = root->right;
        //     root->right = NULL;
        //     invert(root->left);
        //     return;
        // }
        // if(!root->right){
        //     root->right = root->left;
        //     root->left = NULL;
        //     invert(root->right);
        //     return;
        // }
        // swap(root->left->val,root->right->val);
        // invert(root->left);
        // invert(root->right);
        // return;
    }
    bool same(TreeNode *l , TreeNode* r){
        if(!l && r || l && !r) return false;
        if(!l && !r) return true;
        if(l->val != r->val) return false;
        if(!same(l->left,r->left) || !same(l->right,r->right)) return false;
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        invert(root->left);
        return same(root->left,root->right);
    }
};