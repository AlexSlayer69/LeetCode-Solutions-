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

    int solve(TreeNode* root,int &maxs){
        if(root == NULL) return 0;

        int lt = max(0,solve(root->left,maxs));
        int rt = max(0,solve(root->right,maxs));
        maxs = max(maxs,root->val + lt + rt);
        
        return root->val + max(lt,rt);
    }

    int maxPathSum(TreeNode* root) {
        int maxs = INT_MIN; 
        solve(root,maxs);
        return maxs; 
    }
};