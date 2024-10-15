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

    void helper(TreeNode* node, int val,TreeNode* parent){
        if(node == NULL){
            TreeNode* ans = new TreeNode(val);
            if(parent->val > val) parent->left = ans;
            else  parent->right = ans;
            return;
        }
        if(val < node->val){
            helper(node->left,val,node);
            return;
        }
        else{
            helper(node->right,val,node);
        }
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        helper(root,val,NULL);
        return root;
    }
};