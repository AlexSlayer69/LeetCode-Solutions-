/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                Node* el = q.front();
                q.pop();
                temp.push_back(el->val);
                for(auto it : el->children){
                    if(it) q.push(it);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};