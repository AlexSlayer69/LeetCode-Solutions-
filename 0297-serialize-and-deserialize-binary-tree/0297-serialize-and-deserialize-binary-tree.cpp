class Codec {
public:
    string serialize(TreeNode* root) {
           string ans="";
           queue<TreeNode*>q;
           if(!root)return ans;
               ans+=to_string(root->val);
               q.push(root);
               ans+=',';
           while(!q.empty()){
               auto tp=q.front();
               if(tp->left){
                   ans+=to_string(tp->left->val);
                   ans+=',';
                   q.push(tp->left);
               }
               else {
                   ans+='*';
                   ans+=',';
               }
               if(tp->right){
                   ans+=to_string(tp->right->val);
                   ans+=',';
                   q.push(tp->right);
               }
               else {
                   ans+='*';
                   ans+=',';
               }
            q.pop();
           }
           return ans;
    }
    TreeNode* deserialize(string data) {
       queue<string> q;
        string str="";
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(str);
                str="";
            }
            else{
                str+=data[i];
            }
        }
        if(q.size()==0)return NULL;
        TreeNode * root=new TreeNode(stoi(q.front()));
        queue<TreeNode *> par;
        par.push(root);
        q.pop();
        while(!q.empty()){
             auto p=par.front();
             auto m1=q.front();
             q.pop();
             par.pop();
             auto m2=q.front();
             q.pop();
             if(m1!="*"){
                 p->left=new TreeNode(stoi(m1));
                 par.push(p->left);
             }
             if(m2!="*"){
                 p->right=new TreeNode(stoi(m2));
                 par.push(p->right);
             }
        }
        return root;
    }
    
};
