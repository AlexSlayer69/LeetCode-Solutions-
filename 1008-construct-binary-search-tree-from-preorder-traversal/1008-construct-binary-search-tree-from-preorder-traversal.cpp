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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = NULL;
        for(int i : preorder)
            root = InsertBst(root, i);
        return root;
    }
    
    TreeNode* InsertBst(TreeNode* root, int i){
        if(!root) return new TreeNode(i);
        if(i < root->val) root->left = InsertBst(root->left, i);
        else root->right = InsertBst(root->right, i);
        return root;
    }
};