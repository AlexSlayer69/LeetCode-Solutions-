/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int>bfs(TreeNode* target , int k ,unordered_map<TreeNode* ,vector<TreeNode*>>&graph ){
    vector<int>ans;
    unordered_map<TreeNode*,bool>vis;
    queue<pair<TreeNode*,int>>q;
    if(k == 0) ans.push_back(target->val);
    q.push({target,0});
    vis[target] = true;
    while(!q.empty()){
        TreeNode* node = q.front().first;
        int cnt = q.front().second;
        q.pop();
       
        for(auto it : graph[node]){
         if(!vis[it]){
         q.push({it,cnt+1});
         vis[it] = true;
         if(cnt == k-1 && k>=0) 
         ans.push_back(it->val);
        }
    }
 }
        return ans;
    }

  void adjList(TreeNode* node , TreeNode* parent , unordered_map<TreeNode* ,vector<TreeNode*>>&graph){
    if(!node) return;
    if(parent){
        graph[node].push_back(parent);
        graph[parent].push_back(node);
    }
    if(node->left){
        graph[node].push_back(node->left);
        graph[node->left].push_back(node);
    }
    if(node->right){
        graph[node].push_back(node->right);
        graph[node->right].push_back(node);
    }
    adjList(node->left,node,graph);
    adjList(node->right,node,graph);
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,vector<TreeNode*>>graph;
        adjList(root, nullptr , graph);
        return bfs(target,k,graph);
    }
};