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
    TreeNode* helper(int preFirst, int preEnd, vector<int> &preorder, int postFirst, 
    int postEnd, vector<int> &postorder) {
        
        if(preFirst > preEnd) return NULL;
        int preRoot = preorder[preFirst];

        TreeNode* root = new TreeNode(preRoot);
        if(preFirst == preEnd) return root;

        int postRoot = postFirst;
        for(int i=postFirst; i<=postEnd-1; i++) {
            if(postorder[i] == preorder[preFirst+1]) {
                postRoot = i;
                break;
            }
        }

        int postLeftSt = postFirst, postLeftEnd = postRoot;
        int postRightSt = postRoot+1, postRightEnd = postEnd - 1;

        int preLeftSt = preFirst + 1, preLeftEnd = postLeftEnd - postLeftSt + preFirst + 1;
        int preRightSt = preLeftEnd + 1, preRightEnd = preEnd;


        root->left = helper(preLeftSt, preLeftEnd, preorder, postLeftSt, postLeftEnd, postorder);

        root->right = helper(preRightSt, preRightEnd, preorder, postRightSt, postRightEnd, postorder);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return helper(0, n-1, preorder, 0, n-1, postorder);
    }
};