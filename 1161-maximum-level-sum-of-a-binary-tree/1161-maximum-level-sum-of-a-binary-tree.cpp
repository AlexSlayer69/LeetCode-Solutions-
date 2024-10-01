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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int max = root->val,ind = 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* el = q.front();
                q.pop();
                if(el->left != NULL) q.push(el->left);
                if(el->right != NULL) q.push(el->right);
                sum += el->val;
            }
            if(sum > max){
                max = sum;
                ind = level; 
            }
            level++;
        } 
        return ind; 
    }
};