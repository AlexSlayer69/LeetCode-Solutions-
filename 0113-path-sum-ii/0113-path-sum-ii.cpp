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
private:
vector<vector<int>>ans;
void solve(TreeNode *root, int k,int sum,vector<int>v){
    if(root==NULL){
        return;
    }
    sum+=root->val;
    v.push_back(root->val);
    if(sum==k && root->left==NULL && root->right==NULL){
        ans.push_back(v);
    }
    solve(root->left,k,sum,v);
    solve(root->right,k,sum,v);
    v.pop_back();
}
public:
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        if(root==NULL){
           return ans;
        }
       vector<int>v;
       int sum=0;
       solve(root,k,sum,v);
       return ans; 
    }
};