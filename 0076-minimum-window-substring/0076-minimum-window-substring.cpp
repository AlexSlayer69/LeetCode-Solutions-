class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it : t) mp[it]++;
        int m = t.length();
        int l = 0,r = 0;
        int mini = 0;
        int len = INT_MAX;
        while(r < s.length()){
            if(mp[s[r]] > 0) m--;
            mp[s[r]]--;
            r++;

            while(m == 0){
                if(r - l < len){
                    mini = l;
                    len = r-l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) m++;
                l++;
            }
        }
        if(len != INT_MAX){
            return s.substr(mini,len);
        }
        return "";
    }
};