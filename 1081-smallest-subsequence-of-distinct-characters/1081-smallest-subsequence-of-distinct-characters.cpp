class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> last(26,0);
        for(int i =0;i< n;i++){
            last[s[i] - 'a'] = max(i,last[s[i] - 'a']);
        }      
        stack<char> st;
        vector<bool> b(26,false);
        for(int i = 0;i<n;i++){
            if(b[s[i] - 'a']) continue;
            while(!st.empty() && st.top() > s[i] && last[st.top()-'a'] > i){
                b[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            b[s[i] - 'a'] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};