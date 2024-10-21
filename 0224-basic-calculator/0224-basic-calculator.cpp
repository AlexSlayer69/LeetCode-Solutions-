class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0,res = 0,sign = 1;
        for(char c : s){
            if(isdigit(c)) curr = (curr * 10) + (c - '0');
            else if(c == '+' || c == '-'){
                res += sign*curr;
                if( c == '+') sign =1;
                else sign = -1;
                curr = 0;
            }
            else if(c == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')'){
                res += sign*curr;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
                curr = 0;
            }
        }
        return res + sign*curr;
    }
};