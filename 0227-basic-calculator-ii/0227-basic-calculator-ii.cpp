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
            string num = "";
            if(isdigit(s[i])){
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
                string temp2 = "";
                int prev = st.top();
                st.pop();
                int j = i + 1;
                while(isdigit(s[j])){
                    temp2 += s[j];
                    s.erase(s.begin()+j);
                }
                int next = stoi(temp2);
                string temp3;
                if(op == '/') temp3 = to_string(prev/next);
                else if(op == '*') temp3 = to_string(prev*next);
                s.erase(s.begin() + i);
                reverse(temp3.begin(),temp3.end());
                for(auto it : temp3)s.insert(s.begin() + i,it);
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