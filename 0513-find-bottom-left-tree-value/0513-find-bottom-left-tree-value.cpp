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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()){
            int el = q.size();
            int temp = el;
            while(el-- > 0){
                TreeNode* curr = q.front();
                q.pop();
                if(temp-1 == el) ans = curr->val;
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
        }   
        return ans;
    }
};