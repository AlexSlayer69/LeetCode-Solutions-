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
class BSTIterator {
public:
    stack<TreeNode*> anc;
    BSTIterator(TreeNode* root) {
        if(root) anc.push(root);
        while(root && root->left){
            anc.push(root->left);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* el = anc.top();
        anc.pop();
        TreeNode* tmp = (el->right);
        if(tmp) anc.push(tmp);
        while(tmp && tmp->left){
            anc.push(tmp->left);
            tmp = tmp->left;
        }
        return el->val; 
    }
    
    bool hasNext() {
        return !anc.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */