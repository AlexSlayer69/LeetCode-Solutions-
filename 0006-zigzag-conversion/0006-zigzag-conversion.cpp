class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> v(numRows, ""); 
        int j = 0, k = -1;
        string ans = "";

        for(int i = 0; i < s.length(); i++){
            if(j == numRows - 1 || j == 0) k *= (-1); 
            v[j] += s[i];
            if(k == 1) j++;
            else j--;
        }

        for(auto it : v) ans += it; 
        return ans;
    }
};