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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool flag = false;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            
            while(s--){
                TreeNode *curr = q.front();
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                level.push_back(curr->val);
            }
            
            if(flag) reverse(begin(level), end(level));
            flag = !flag;
            ans.push_back(level);
        }
        
        return ans;
    }
};