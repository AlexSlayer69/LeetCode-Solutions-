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
    pair<int,pair<int,int>> helper(TreeNode *node,int &sum){
        if(!node) return {0, {INT_MAX, INT_MIN}};
        
        pair<int,pair<int,int>> lt = helper(node->left,sum);
        pair<int,pair<int,int>> rt = helper(node->right,sum);
        
        if(lt.second.second < node->val && node->val < rt.second.first){
            int s = node->val + lt.first + rt.first;
            sum = max(sum, s);
            int mini = min({node->val, lt.second.first, rt.second.first});
            int maxi = max({node->val, lt.second.second, rt.second.second});
            return {s, {mini, maxi}};
        }
        return {0, {INT_MIN, INT_MAX}};
    }
    
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return sum;
    }

};