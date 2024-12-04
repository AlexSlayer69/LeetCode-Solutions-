class Solution {
public:
    void solve(int currNum,int n,vector<int>&result){
        if(currNum>n) return ;
        result.push_back(currNum);
        for(int j=0;j<=9;j++){
            int nextNum=(currNum*10)+j;
            if(nextNum<=n){
                solve(nextNum,n,result);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i=1;i<=9;i++){
            solve(i,n,result);
        }
        return result;
    }
};