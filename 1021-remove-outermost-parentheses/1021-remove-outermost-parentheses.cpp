class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        int i =0;
        int n = s.size();

        for(int j=0;j<n;j++){
            if(s[j]=='(') st.push('(');
            else st.pop();
            
            if(st.empty()){
                ans += s.substr(i+1, j-i-1);
                i = j+1;
            }
        }

        return ans;
    }
};