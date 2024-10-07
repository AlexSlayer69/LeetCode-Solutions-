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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;

        if(!root) return v;
        
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> vis;

            for(int i =0; i<n; i++) {
                TreeNode* node = q.front();
                q.pop();
                vis.push_back(node->val);
                
                if(node->left)
                   q.push(node->left);
                if(node->right)
                   q.push(node->right);
            }
            
            long long  int sum =0;
            
            for(auto it : vis){
                if(it <= INT_MAX) sum += it;
            }
            double level = vis.size();
            v.push_back(static_cast<double>(sum/level));
            vis.clear();
        }
        return v;
    }
};