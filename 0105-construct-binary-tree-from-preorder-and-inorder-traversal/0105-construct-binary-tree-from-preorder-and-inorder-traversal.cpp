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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return root;
        
        int i = find(inorder.begin(),inorder.end(),preorder[0])- inorder.begin();
    
        vector<int> lp = vector<int>(preorder.begin()+1,preorder.begin()+i+1);
        vector<int> rp = vector<int>(preorder.begin()+i+1,preorder.end());
        vector<int> li = vector<int>(inorder.begin(),inorder.begin()+i);
        vector<int> ri = vector<int>(inorder.begin()+i+1,inorder.end());

        root->left = buildTree(lp,li);
        root->right = buildTree(rp,ri);
        return root;
    }
};