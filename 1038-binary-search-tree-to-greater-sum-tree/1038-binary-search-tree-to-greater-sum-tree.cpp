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
    TreeNode* bstToGst(TreeNode* root) {

        if(!root) return NULL;

        TreeNode* curr = root;

        int sum = 0;

        while(curr) {
            if(!curr->right) {
                sum += curr->val;
                curr->val = sum;

                curr = curr->left;
            } else {
                TreeNode* temp = curr->right;

                while(temp->left && temp->left != curr) {
                    temp = temp->left;
                }

                if(!temp->left) {
                    temp->left = curr;
                    curr = curr->right;
                } else {
                    sum += curr->val;
                    curr->val = sum;

                    temp->left = NULL;
                    curr = curr->left;
                }
            }
        }

        return root;
    }
};