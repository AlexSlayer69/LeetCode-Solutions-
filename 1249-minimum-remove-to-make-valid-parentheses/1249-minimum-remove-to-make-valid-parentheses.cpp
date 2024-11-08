class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (!v.empty() && s[v.back()] == '(')
                    v.pop_back();
                else
                    v.push_back(i);
            } else if (s[i] == '(')
                v.push_back(i);
        }

        if (v.size() == 0)
            return s;
        int m = v.size();

        int curr = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (curr < m && i == v[curr])
                curr++;
            else
                ans += s[i];
        }

        return ans;
    }
};