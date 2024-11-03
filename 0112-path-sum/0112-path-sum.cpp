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

    bool solve(int curr,int target,TreeNode* node){
        if(!node) return false;
        if(!node->left && !node->right) return (curr+node->val == target);
        else{
            curr += node->val;
            return solve(curr,target,node->left) || solve(curr,target,node->right);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        //if(!root) return dalse'
        return solve(0,targetSum,root);
    }
};