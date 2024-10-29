class Solution {
public:

    void solve(int i,string str,long sum,long prev,string num,int &target,vector<string> &ans){
        if(i == num.size()){
            if(sum == target){
                ans.push_back(str);
            }
            return;
        }

        for(int j = i;j<num.size();j++){
            if(j > i && num[i] == '0') break;
            string temp = num.substr(i,j-i+1);
            long n = stol(temp);
            if(!i) solve(j+1,temp,n,n,num,target,ans);
            else{
                solve(j+1,str+'+'+temp,sum+n,n,num,target,ans);
                solve(j+1,str+'-'+temp,sum-n,-n,num,target,ans);
                solve(j+1,str+'*'+temp,sum-prev+(prev*n),prev*n,num,target,ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0,"",0,0,num,target,ans);
        return ans;
    }
};