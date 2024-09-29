class Solution {
public:

    void solve(int o,int c,string s, vector<string> &v,int n){
        if(o < c) return;
        if(o == n && c == n){
            v.push_back(s);
            return;
        }
        if(o == n){         
            solve(o,c+1,s + ')',v,n);
            return;
        }
        solve(o+1,c,s + '(',v,n);
        solve(o,c+1,s+')',v,n);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "(";
        solve(1,0,s,v,n);
        return v;
    }
}; 