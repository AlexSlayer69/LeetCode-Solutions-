class Solution {
public:
    int longestValidParentheses(string st) {
        int n = st.length();
        stack<int> s;
        s.push(-1);
        int maxi = 0;

        for(int i =0;i<n;i++){
            if(st[i] == '(') s.push(i);
            else{
                s.pop();
                if(s.empty()) s.push(i);
                else maxi = max(maxi,i - s.top());
            }
        }
        return maxi;
    }
};