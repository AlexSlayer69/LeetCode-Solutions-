class Solution {
public:

    void dfs(int i, vector<string>& curr,string& s, vector<vector<string>>& ans){
        if(i == s.size()) ans.push_back(curr);
        int start = i;
        for(;i < s.size();i++){
            string temp = s.substr(start,i-start+1);
            curr.push_back(temp);
            bool flag = true;
            for(int j=0;j<temp.size();j++){
                if(temp[j] != temp[temp.size()-1-j]) flag = false;
            }
            if(flag) dfs(i+1,curr,s,ans);
            curr.pop_back();
        }
    } 


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(0,temp,s,ans);
        return ans;
    }
};