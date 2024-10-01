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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return vector<int>();
        vector<int> v;

        while(root != NULL){
            v.push_back(root->val);
            if(root->right != NULL){
                root = root->right;
                continue;
            }
            else if(root->left != NULL){
                root = root->left;
            }
            else{
                break;
            }
        }
        return v;
    }
};