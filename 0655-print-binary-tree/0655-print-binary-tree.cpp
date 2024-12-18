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
int getans(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=getans(root->left);
    int r=getans(root->right);
    return 1+max(l,r);
   
}
    vector<vector<string>> printTree(TreeNode* root) {
        int height=0;
       height=getans(root);
       height=height-1;
        
       cout<<height;
       vector<vector<string>>v(height+1,vector<string>(pow(2,height+1)-1));
       int h=-1;
       queue<pair<TreeNode*,int>>q;
       int n=pow(2,height+1)-1;
       int index=(n-1)/2;
       q.push({root,index});
       while(!q.empty())
       {
        h++;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* temp=q.front().first;
            int c=q.front().second;
            q.pop();
            if(h==0)
            {
                v[h][index]=to_string(temp->val);
            }
            else{
                v[h][c]=to_string(temp->val);
            }
            if(temp->left)
            {
                q.push({temp->left,c-pow(2,height-h-1)});
            }
            if(temp->right)
            {
                q.push({temp->right,c+pow(2,height-h-1)});
            }
        }
    }
    return v;
    }

};