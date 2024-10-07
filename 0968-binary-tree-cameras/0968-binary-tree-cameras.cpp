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
    int solve(TreeNode* root,int &ans) {
        if(!root) return 1;

        int lt = solve(root->left,ans);
        int rt = solve(root->right,ans);

        if(lt==0 || rt==0) {ans++; return 2;}
        if(lt==2 || rt==2) return 1;
        
        return 0;

    }

    int minCameraCover(TreeNode* root) {
        int ans=0;
        return solve(root,ans) == 0 ? ans+1 : ans;
    }
};