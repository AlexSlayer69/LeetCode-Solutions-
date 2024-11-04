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

    void inord(TreeNode* root,vector<int> &inorder){
        if(!root){
            inorder.push_back(-1e4);
            return;
        }
        if(!root->left && !root->right) {
            inorder.push_back(root->val);
            return;
        }
        inord(root->left,inorder);
        inorder.push_back(root->val);
        inord(root->right,inorder);
        return;
    }

    bool isSymmetric(TreeNode* root) {
        vector<int> inorder;
        inord(root,inorder);
        for(int i =0;i<=inorder.size()/2;i++){
            if(inorder[i] != inorder[inorder.size()-i-1]) return false;
        }
        return true;
        
    }
};