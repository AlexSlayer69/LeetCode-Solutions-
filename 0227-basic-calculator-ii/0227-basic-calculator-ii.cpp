class Solution {
public:
    int calculate(string s) {
        for(int i =0;i<s.length();i++){
            if(s[i] == ' '){
                s.erase(s.begin() + i);
                i--;
            }
        }    
        stack<int> st;
        for(int i =0;i < s.length();i++){
            if(isdigit(s[i])){
                string num = "";
                num += s[i];
                s.erase(s.begin() + i);
                while(isdigit(s[i])){
                    num += s[i];
                    s.erase(s.begin() + i);
                } 
                st.push(stoi(num));
            }
            if(s[i] == '/' || s[i] == '*'){
                char op = s[i];
                s.erase(s.begin()+i);
                int prev = st.top();
                st.pop();
                int j = i;
                string temp2 = "";
                while(isdigit(s[j])){
                    temp2 += s[j];
                    s.erase(s.begin()+j);
                }
                int next = stoi(temp2);
                if(op == '/') st.push(prev/next);
                else st.push(prev*next);
                i--;
            }
        }
        stack<int> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        cout << s << endl;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '-' || s[i] == '+'){
                char op = s[i];
                int prev = st2.top();
                st2.pop();
                int next = st2.top();
                st2.pop();
                if(op == '-') st2.push(prev-next);
                else st2.push(prev+next);
            }
        }
        return st2.top();
    }
};