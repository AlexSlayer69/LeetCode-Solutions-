class Solution {
public:

    string solve(int &i, string s){
        int n =0;
        string ans = "";
        while(i < s.length()){
            char c = s[i];
            if(c >= '0' && c <= '9') n = n*10 + c - '0';
            else if(c == '['){
                string temp = solve(++i,s);
                while(n > 0){
                    ans += temp;
                    n--;
                }
            }
            else if(c == ']') return ans;
            else ans += c;
            i++;
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(i,s);
    }
};