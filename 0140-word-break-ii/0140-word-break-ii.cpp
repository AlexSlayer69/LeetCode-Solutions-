class Solution {
public:

     void solve(int ind, int n, string& r, string& s, vector<string>& wordDict, vector<string>& ans){
        if(ind >= n){
            ans.push_back(r);
            return;
        }
        for(int i=ind;i<n;i++){
            string s1 = s.substr(ind,i-ind+1);
            if(find(wordDict.begin(),wordDict.end(),s1)!=wordDict.end()){
                string r1;
                if(r.length()==0) r1=s1;
                else r1 = r + " " + s1;
                solve(i+1,n,r1,s,wordDict,ans);
            }
        }
    }



    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        string r;
        vector<string> ans;
        solve(0,n,r,s,wordDict,ans);
        return ans;
    }
};