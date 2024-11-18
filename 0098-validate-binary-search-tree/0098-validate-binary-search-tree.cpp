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

    bool solve(TreeNode* root,long smaller, long bigger){
        if(!root) return true;
        if(root->val >= bigger || root->val <= smaller) return false;
        else return solve(root->left,smaller,min(bigger,(long)root->val)) && 
             solve(root->right,max(smaller,(long)root->val),bigger);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return solve(root->left,(long)INT_MIN-1,root->val) && 
             solve(root->right,root->val,(long)INT_MAX+1);
    }
};