class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256,-1);
        vector<int> v2(256,-1);
        for(int i =0;i<s.length();i++){
            if(v1[s[i]] == -1) v1[s[i]] = i;
            if(v2[t[i]] == -1) v2[t[i]] = i;
            if(v1[s[i]] !=  v2[t[i]]) return false;
        }
        return true;
    }
};