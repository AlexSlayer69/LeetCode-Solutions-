class Solution {
public:

    void backtrack(int i,string &temp,int open,int close,
                   int o,int c,string &s,unordered_set<string> &ans,int &len){
        
        // if(i == s.length()) {
        //     cout << temp << " " << open << " " << close << " " << o << " " << c << " " << endl;
        // }
        if(open < 0 || close < 0) return;
        if(o < c) return;
        if(i == s.length() && o != c) return;
        if(i == s.length() && (open != 0 || close != 0)) return;
        if(i == s.length() && (temp.length() != len)) return;
        if(i == s.length()){
            ans.insert(temp);
            return;
        }

        if(s[i] == '('){
             backtrack(i+1,temp,open-1,close,o,c,s,ans,len);
             temp += s[i];
             backtrack(i+1,temp,open,close,o+1,c,s,ans,len); 
             temp.erase(temp.end()-1);
             return;
        }
        else if(s[i] == ')'){
            backtrack(i+1,temp,open,close-1,o,c,s,ans,len);
            temp += s[i];
            backtrack(i+1,temp,open,close,o,c+1,s,ans,len); 
            temp.erase(temp.end()-1);
            return;
        }
        else{
            temp += s[i];
            backtrack(i+1,temp,open,close,o,c,s,ans,len); 
            temp.erase(temp.end()-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        stack<pair<char,int>> st;
        int close = 0,open = 0;
        for(int i =0;i < s.length();i++){
            if(s[i] == '(') st.push({'(',i});
            else if(s[i] == ')'){
                if(st.empty()) close++;
                else st.pop();
            }
        }
        while(!st.empty()){
            open++;
            st.pop();
        }

        unordered_set<string> ans;
        int len = s.size()-open-close;
        string temp = "";
        backtrack(0,temp,open,close,0,0,s,ans,len);
        
        return vector<string>(ans.begin(),ans.end());
    }
};