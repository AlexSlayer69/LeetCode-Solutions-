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

    vector<string> solve(TreeNode* &root){
        if(root==NULL)return {};
        
        vector<string>ans;
        string root_val = to_string(root->val);
        vector<string>left  = solve(root->left);
        vector<string>right = solve(root->right);
        for(auto it:left) ans.push_back(root_val + "->" + it);
        for(auto it:right) ans.push_back(root_val + "->" + it);
        
        if(ans.size()==0)return{root_val};
        return ans;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        return solve(root);
    }
};