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
    
    int zigzag(TreeNode* root,int dir,map<pair<TreeNode*,int>,int> &m){
        if(!root){
            return 0;
        }
        if(m[{root,dir}]!=0){
            return m[{root,dir}];
        }
        int c = 0;
        if(dir){
            c = 1 + zigzag(root->right,0,m);
        }
        else{
            c = 1 + zigzag(root->left,1,m);
        }
        return m[{root,dir}] = c;
    }
    void longest(TreeNode* root,int &ans,map<pair<TreeNode*,int>,int> &m){
        if(!root){
            return;
        }
        int countRight = zigzag(root,1,m);
        int countLeft = zigzag(root,0,m);
        ans = max(ans,max(countRight,countLeft));
        longest(root->left,ans,m);
        longest(root->right,ans,m);
    }
    int longestZigZag(TreeNode* root){
       int ans = 0;
       map<pair<TreeNode*,int>,int> m;
       longest(root,ans,m);
       return ans-1;
    }
};