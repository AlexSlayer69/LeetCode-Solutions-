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
void addrow(int h,TreeNode* root,int val,int depth){
    if(root==NULL)return ;
    if(h==depth-1){
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        TreeNode* temp=new TreeNode(val);
        TreeNode* t2=new TreeNode(val);
        root->left=temp;
        temp->left=left;
        root->right=t2;
        t2->right=right;
        return ;
    }
   addrow(h+1,root->left,val,depth);
   addrow(h+1,root->right,val,depth);
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1){
        TreeNode* temp=new TreeNode(val);
        temp->left=root;
        return temp;
       } 
       addrow(1,root,val,depth);
       return root;
    }
};